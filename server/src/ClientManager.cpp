#include "ClientManager.h"

ClientManager::~ClientManager()
{
    // Join all threads before destruction
    for (auto& [userId, thread] : m_threads)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }
}

void ClientManager::addClient(Client&& client)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_clients.emplace(client.getUserId(), std::move(client));
}

void ClientManager::removeClient(unsigned int userId)
{
    removeThread(userId);
    removeSession(userId);

    // Prevent deadlock by locking the mutex only for the duration of the erase operation
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_clients.erase(userId);
    }
}

std::vector<const Client*> ClientManager::getAllClients() const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::vector<const Client*> clients;
    for (const auto& [userId, client] : m_clients)
    {
        clients.push_back(&client);
    }
    return clients;
}

std::vector<Client*> ClientManager::getAllClients()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::vector<Client*> clients;
    for (auto& [userId, client] : m_clients)
    {
        clients.push_back(&client);
    }
    return clients;
}

Client* ClientManager::getClientByUsername(const std::string& username)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto& [userId, client] : m_clients)
    {
        if (client.getUsername() == username)
        {
            return &client;
        }
    }
    return nullptr;
}

Client* ClientManager::getClientById(unsigned int userId)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_clients.find(userId);
    if (it != m_clients.end())
    {
        return &it->second;
    }
    return nullptr;
}

void ClientManager::addThread(unsigned int userId, std::thread&& thread)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_threads.emplace(userId, std::move(thread));
}

void ClientManager::removeThread(unsigned int userId)
{
    std::thread threadToJoin;

    {
        std::lock_guard<std::mutex> lock(m_mutex);

        auto it = m_threads.find(userId);

        if (it == m_threads.end())
        {
            return;
        }

        threadToJoin = std::move(it->second);
        m_threads.erase(it);
    }

    if (threadToJoin.joinable())
    {
        threadToJoin.join();
    }
}

void ClientManager::addSession(unsigned int userId, ClientSession&& session)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_sessions.emplace(userId, std::move(session));
}

void ClientManager::removeSession(unsigned int userId)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_sessions.erase(userId);
}

ClientSession* ClientManager::getSession(unsigned int userId)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_sessions.find(userId);
    if (it != m_sessions.end())
    {
        return &it->second;
    }
    return nullptr;
}

const ClientSession* ClientManager::getSession(unsigned int userId) const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_sessions.find(userId);
    if (it != m_sessions.end())
    {
        return &it->second;
    }
    return nullptr;
}