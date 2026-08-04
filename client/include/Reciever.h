#pragma once
#include <string>
#include <atomic>
#include <functional>

#include "server/include/Socket.h"
#include "common/include/Message.h"

class Receiver {
private:
    Socket& m_socket; 
    std::atomic<bool> m_running; // Atomic flag to control the receiving loop
    std::function<void(const Message&)> m_callback; // Callback function to handle received messages
public:
    // Constructor and Destructor
    explicit Receiver(Socket& socket, std::function<void(const Message&)> callback);
    ~Receiver() = default;

    // Delete copy constructor and assignment operator to prevent copying
    Receiver(const Receiver&) = delete;
    Receiver& operator=(const Receiver&) = delete;

    void recieveLoop(); // Method to start the receiving loop
    void stop(); // Method to stop the receiver

    Message receiveMessage(std::string& message); 
};