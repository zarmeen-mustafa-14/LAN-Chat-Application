#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include "Socket.h"

class Listener
{
private:
    Socket m_listenSocket;
public:
    // Constructor and Destructor
    Listener();
    ~Listener() = default;

    // Prevent copying
    Listener(const Listener &) = delete;
    Listener &operator=(const Listener &) = delete;

    // Allow moving
    Listener(Listener &&) noexcept;
    Listener &operator=(Listener &&) noexcept;

    // Start listening on the specified IP address and port
    bool startListening(const std::string &ip, unsigned short port, int backlog = SOMAXCONN);
    void stopListening(); // Stop listening and close the socket

    //getter for the underlying socket
    SOCKET getSocket() const;
};