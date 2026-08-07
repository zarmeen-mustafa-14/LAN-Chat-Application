#include "Receiver.h"

Receiver::Receiver(Socket& socket, std::function<void(const Message&)> callback)
    : m_socket(socket), m_running(false), m_callback(callback) {
}

void Receiver::receiveLoop() {
    m_running = true;
    while (m_running) {
        std::string data;
        if (!m_socket.receive(data)) {
            break; // Exit the loop if receiving fails
        }
        Message message = Parser::parse(data);
        if (m_callback) {
            m_callback(message); // Invoke the callback with the received message
        }
            
    }
    m_running = false; // Ensure the running flag is reset when the loop exits
}

void Receiver::stop() {
    m_running = false;
}