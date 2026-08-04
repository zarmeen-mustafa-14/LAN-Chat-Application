#pragma once

#include <string>
#include <thread>

#include "Receiver.h"
#include "Sender.h"
#include "server/include/Socket.h"
#include "common/include/Message.h"

enum class ConnectionState {
    DISCONNECTING,
    DISCONNECTED,
    CONNECTING,
    CONNECTED
};

class NetworkClient {
    private:
        Socket m_socket; // Socket for network communication
        Receiver m_receiver; // Receiver object to handle incoming messages
        Sender m_sender; // Sender object to handle outgoing messages
        std::thread m_receiveThread; // Thread for receiving messages
        ConnectionState m_connectionState; // Variable to track the client's state

        void onMessageReceived(const Message& message); // Callback function for handling received messages
    public:
        // Constructor and Destructor
        NetworkClient();
        ~NetworkClient();

        // Delete copy constructor and assignment operator to prevent copying
        NetworkClient(const NetworkClient&) = delete;  
        NetworkClient& operator=(const NetworkClient&) = delete;

        bool connect(const std::string& ip, unsigned short port); // Method to connect to the server
        void disconnect(); // Method to disconnect from the server

        bool sendMessage(const Message& message); // Method to send a message to the server

        ConnectionState getConnectionState() const; // Method to get the current connection state
};