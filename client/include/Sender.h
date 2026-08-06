#pragma once

#include "Socket.h"
#include "Message.h"

class Sender {
private:
    Socket& m_socket;
public:
    // Constructor and Destructor
    explicit Sender(Socket& socket);
    ~Sender() = default;

    // Delete copy constructor and assignment operator to prevent copying
    Sender(const Sender&) = delete;
    Sender& operator=(const Sender&) = delete;

    bool sendMessage(const Message& message);
};