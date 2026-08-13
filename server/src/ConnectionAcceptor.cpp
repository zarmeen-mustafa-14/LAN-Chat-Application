#include "ConnectionAcceptor.h"
#include <stdexcept>

ConnectionAcceptor::ConnectionAcceptor(Listener &listener) : m_listener(listener) {
}

Socket ConnectionAcceptor::acceptConnection() {
    SOCKET clientSocket = 
                        ::accept(m_listener.getSocket(), nullptr, nullptr);
    if (clientSocket == INVALID_SOCKET) {
        return Socket(); // Return an invalid Socket object if accept fails
    }
    return Socket(clientSocket);
}