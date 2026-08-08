#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

class Socket {
private:
    SOCKET m_sock;
public:
    // Constructor and Destructor
    Socket();
    ~Socket();
    Socket(SOCKET sock); // Constructor that takes a SOCKET (for client sockets)

    // Delete copy constructor and assignment operator to prevent copying
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;

    // Move constructor and move assignment operator
    Socket(Socket&& other) noexcept; // Move constructor
    Socket& operator=(Socket&& other) noexcept; // Move assignment operator

    //getter
    SOCKET getSocket() const;

    // Socket operations
    bool create();
    bool bind(const std::string& ip, unsigned short port);
    bool listen(int backlog = SOMAXCONN);
    void shutdown(); // Shutdown the socket for sending and receiving
    void close(); // Closes the socket and releases resources

    // Sends raw data through the underlying socket
    bool send(const std::string& data);

    // Receives raw data from the underlying socket
    bool receive(std::string& data);

    // Establishes a connection using the underlying socket
    bool connect(const std::string& ip, unsigned short port);

    bool isValid() const;
    int getLastError() const;
};