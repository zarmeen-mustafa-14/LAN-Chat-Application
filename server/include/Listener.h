#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include "Socket.h"

class Listener
{
private:
    Socket listenSocket;
public:
    // Constructor and Destructor
    Listener();
    ~Listener();

    // Prevent copying
    Listener(const Listener &) = delete;
    Listener &operator=(const Listener &) = delete;

    // Allow moving
    Listener(Listener &&) noexcept;
    Listener &operator=(Listener &&) noexcept;

    // Start listening on the specified IP address and port
    bool startListening(const std::string &ip, unsigned short port, int backlog = SOMAXCONN);

    //getter for the underlying socket
    SOCKET getSocket() const;
};