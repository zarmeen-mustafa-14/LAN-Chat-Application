#pragma once

#include "server/include/Socket.h"
#include "common/include/Message.h"

class Receiver {
private:
    Socket& m_socket; 
    bool m_running; // Flag to indicate if the receiver is running
public:
    // Constructor and Destructor
    explicit Receiver(Socket& socket);
    ~Receiver() = default;

    // Delete copy constructor and assignment operator to prevent copying
    Receiver(const Receiver&) = delete;
    Receiver& operator=(const Receiver&) = delete;

    void recieveLoop(); // Method to start the receiving loop
    void stop(); // Method to stop the receiver

    Message receiveMessage(std::string& message); 
};