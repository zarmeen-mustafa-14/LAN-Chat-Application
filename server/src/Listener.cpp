#include "Listener.h"


Listener::Listener() : m_listenSocket() {}

Listener::Listener(Listener &&other) noexcept : m_listenSocket(std::move(other.m_listenSocket)) {}
Listener &Listener::operator=(Listener &&other) noexcept {
    if (this != &other) {
        m_listenSocket = std::move(other.m_listenSocket);
    }
    return *this;
}

bool Listener::startListening(const std::string &ip, unsigned short port, int backlog) {
    if (!m_listenSocket.create()) {
        return false;
    }
    if (!m_listenSocket.bind(ip, port)) {
        m_listenSocket.close(); // Close the socket if binding fails
        return false;
    }
    if (!m_listenSocket.listen(backlog)) {
        m_listenSocket.close(); // Close the socket if listening fails
        return false;
    }
    return true;
}

SOCKET Listener::getSocket() const {
    return m_listenSocket.getSocket();
}