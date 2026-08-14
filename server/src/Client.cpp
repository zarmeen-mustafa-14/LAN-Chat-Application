#include "Client.h"
#include <utility>

Client::Client(const std::string& ip, unsigned short port, unsigned int userId, const std::string& username)
    : m_ip(ip), m_port(port), m_userId(userId), m_username(username)
{
}

Client::Client(Client&& other) noexcept
    : m_ip(std::move(other.m_ip)), m_port(other.m_port), m_userId(other.m_userId), m_username(std::move(other.m_username))
{
    other.m_port = 0;
    other.m_userId = 0;
}

Client& Client::operator=(Client&& other) noexcept
{
    if (this != &other)
    {
        m_ip = std::move(other.m_ip);
        m_port = other.m_port;
        m_userId = other.m_userId;
        m_username = std::move(other.m_username);

        other.m_port = 0;
        other.m_userId = 0;
    }
    return *this;
}

const std::string& Client::getIp() const
{
    return m_ip;
}

unsigned short Client::getPort() const
{
    return m_port;
}

unsigned int Client::getUserId() const
{
    return m_userId;
}

const std::string& Client::getUsername() const
{
    return m_username;
}