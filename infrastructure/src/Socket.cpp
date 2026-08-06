#include "Socket.h"

Socket::Socket() : m_sock(INVALID_SOCKET) {}
Socket::~Socket() { close(); }
Socket::Socket(SOCKET sock) : m_sock(sock) {}

Socket::Socket(Socket &&other) noexcept : m_sock(other.m_sock)
{
    other.m_sock = INVALID_SOCKET; // Leave the moved-from object in a valid state
}

Socket &Socket::operator=(Socket &&other) noexcept
{
    if (this != &other)
    {
        close(); // Close the current socket if it's valid
        m_sock = other.m_sock;
        other.m_sock = INVALID_SOCKET; // Leave the moved-from object in a valid state
    }
    return *this;
}

SOCKET Socket::getSocket() const
{
    return m_sock;
}

bool Socket::create()
{
    if (isValid())
    {
        close();
    }

    m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    return m_sock != INVALID_SOCKET;
}

bool Socket::bind(const std::string &ip, unsigned short port)
{
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &addr.sin_addr) <= 0)
    {
        return false;
    }

    return ::bind(m_sock, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) != SOCKET_ERROR;
}

bool Socket::listen(int backlog)
{
    return ::listen(m_sock, backlog) != SOCKET_ERROR;
}

void Socket::close()
{
    if (m_sock != INVALID_SOCKET)
    {
        closesocket(m_sock);
        m_sock = INVALID_SOCKET;
    }
}

bool Socket::send(const std::string &data)
{
    if (!isValid())
    {
        return false;
    }
    int totalBytesSent = 0;
    const int dataSize = static_cast<int>(data.size());
    while (totalBytesSent < dataSize)
    {
        int bytesSent = ::send(m_sock, 
                                data.c_str() + totalBytesSent, 
                                dataSize - totalBytesSent, 
                                0);
        if (bytesSent == SOCKET_ERROR)
        {
            return false; // Sending failed
        }
        totalBytesSent += bytesSent;
    }

    return true;
}

bool Socket::receive(std::string &data)
{
    if (!isValid())
    {
        return false;
    }

    constexpr int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int bytesReceived = ::recv(m_sock, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived == SOCKET_ERROR || bytesReceived == 0)
    {
        return false; // Receiving failed or connection closed
    }

    buffer[bytesReceived] = '\0'; // Null-terminate the received data
    data.assign(buffer, bytesReceived);
    return true;
}

bool Socket::isValid() const
{
    return m_sock != INVALID_SOCKET;
}

int Socket::getLastError() const
{
    return WSAGetLastError();
}