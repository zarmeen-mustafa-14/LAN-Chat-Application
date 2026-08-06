#include "Receiver.h"

Receiver::Receiver(Socket& socket, std::function<void(const Message&)> callback)
    : m_socket(socket), m_running(false), m_callback(callback) {
}

void Receiver::receiveLoop() {
    m_running = true;
    while (m_running) {
        std::string message;
        Message receivedMessage = receiveMessage(message);
        if (!message.empty()) {
            m_callback(receivedMessage);
        }
    }
}

void Receiver::stop() {
    m_running = false;
}

