#include "Sender.h"
#include "Socket.h"
#include "Serializer.h"
#include "MessageValidator.h"

#include <iostream>

Sender::Sender(Socket& socket) : m_socket(socket) {}

bool Sender::sendMessage(const Message& message) {
    // Validate the message before sending  
    if (!MessageValidator::isValid(message)) {
        std::cerr << "Message validation failed: " << MessageValidator::getRejectionReason(message) << std::endl;
        return false;
    }
    // Serialize the message to a string
    std::string serializedMessage = Serializer::serialize(message);

    // Send the serialized message over the socket
    return m_socket.send(serializedMessage);
}