#include "Socket.h"

Socket :: Socket() : m_sock(INVALID_SOCKET) {}
Socket :: ~Socket() { close(); }
Socket :: Socket(SOCKET sock) : m_sock(sock) {}

Socket :: Socket(Socket&& other) noexcept : m_sock(other.m_sock) {
    other.m_sock = INVALID_SOCKET; // Leave the moved-from object in a valid state
}

Socket& Socket :: operator=(Socket&& other) noexcept {
    if (this != &other) {
        close(); // Close the current socket if it's valid
        m_sock = other.m_sock;
        other.m_sock = INVALID_SOCKET; // Leave the moved-from object in a valid state
    }
    return *this;
}

SOCKET Socket :: getSocket() const {
    return m_sock;
}

bool Socket :: create() {
    m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    return m_sock != INVALID_SOCKET;
}

bool Socket :: bind(const std::string& ip, unsigned short port) {
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

    return ::bind(m_sock, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != SOCKET_ERROR;
}

bool Socket :: listen(int backlog) {
    return ::listen(m_sock, backlog) != SOCKET_ERROR;
}

void Socket :: close() {
    if (m_sock != INVALID_SOCKET) {
        closesocket(m_sock);
        m_sock = INVALID_SOCKET;
    }
}

bool Socket :: isValid() const {
    return m_sock != INVALID_SOCKET;
}