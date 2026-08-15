#pragma once

#include <vector>
#include <unordered_map>
#include <mutex>
#include <thread>
#include <optional>

#include "Client.h"
#include "ClientSession.h"

class ClientManager
{
    private:
        std::unordered_map<unsigned int, Client> m_clients; // Map of userId to Client
        std::unordered_map<unsigned int, std::thread> m_threads; // Map of userId to thread handling the client
        mutable std::mutex m_mutex; // Mutex for thread-safe access to m_clients and m_threads
        std::unordered_map<unsigned int, ClientSession> m_sessions; // Map of userId to ClientSession for managing client sessions

    public:
        ClientManager() = default;
        ~ClientManager();

        // Client management
        
        void addClient(Client&& client); // Add a new client to the manager
        void removeClient(unsigned int userId); // Remove a client by user ID

        std::vector<Client> getAllClients() const; // Get all clients 
        std::vector<Client> getAllClients(); // Used for modifying the list of clients in a thread-safe manner

        std::optional<Client> getClientByUsername(const std::string& username) const;  // Check if a client exists by username
        std::optional<Client> getClientById(unsigned int userId) const; // Check if a client exists by user ID

        // Thread management
        void addThread(unsigned int userId, std::thread&& thread); // Add a thread for a client
        void removeThread(unsigned int userId); // Remove a thread for a client

        // Session management

        void addSession(unsigned int userId, ClientSession&& session); // Add a session for a client
        void removeSession(unsigned int userId); // Remove a session for a client
        ClientSession* getSession(unsigned int userId); // Get a session for a client
        const ClientSession* getSession(unsigned int userId) const;

};