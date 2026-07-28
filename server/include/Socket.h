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
    void close();

    bool isValid() const;
};