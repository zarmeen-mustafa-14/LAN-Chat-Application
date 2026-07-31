#pragma once

#include <vector>
#include <unordered_map>
#include <mutex>
#include <thread>

#include "Client.h"

class ClientManager
{
    private:
        std::unordered_map<unsigned int, Client> m_clients; // Map of userId to Client
        std::unordered_map<unsigned int, std::thread> m_threads; // Map of userId to thread handling the client
        std::mutex m_mutex; // Mutex for thread-safe access to m_clients and m_threads

    public:
        ClientManager() = default;
        ~ClientManager();

        // Add a new client to the manager
        void addClient(Client&& client);

        // Remove a client by user ID
        void removeClient(unsigned int userId);

        // Getter
        const Client* getClient(unsigned int userId) const; // Get a client by user ID
        std::vector<const Client*> getAllClients() const; // Get all clients

        Client* getClient(unsigned int userId); // Get a client by user ID for modification
        std::vector<Client*> getAllClients(); // Used for modifying the list of clients in a thread-safe manner

        void addThread(unsigned int userId, std::thread&& thread); // Add a thread for a client
        void removeThread(unsigned int userId); // Remove a thread for a client
};