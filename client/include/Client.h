#pragma once
#include <string>
#include "server/include/Socket.h"

class Client
{
private:
    Socket m_socket;
    std::string m_ip;
    unsigned short m_port;

public:
    // Constructor and Destructor
    Client(Socket&& socket, const std::string& ip, unsigned short port);
    ~Client() = default;

    //copy constructor and assignment operator are deleted to prevent copying
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;

    Client(Client&& other) noexcept; // Move constructor
    Client& operator=(Client&& other) noexcept; // Move assignment operator

    // Getters
    const std::string& getIp() const;
    unsigned short getPort() const;

    //non-const getter used to modify the socket if needed by ClientManager
    Socket& getSocket();
    const Socket& getSocket() const;

};