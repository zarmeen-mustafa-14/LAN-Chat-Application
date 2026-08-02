#pragma once
#include <string>

class Client
{
private:
    std::string m_ip;
    unsigned short m_port;
    unsigned int m_userId;
    std::string m_username;

public:
    // Constructor and Destructor
    Client(const std::string& ip, unsigned short port, unsigned int userId, const std::string& username);
    ~Client() = default;

    //copy constructor and assignment operator are deleted to prevent copying
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;

    Client(Client&& other) noexcept; // Move constructor
    Client& operator=(Client&& other) noexcept; // Move assignment operator

    // Getters
    const std::string& getIp() const;
    unsigned short getPort() const;
    unsigned int getUserId() const;
    const std::string& getUsername() const;
};