#include "Server.h"

Server::Server()
    : m_connectionAcceptor(m_listener),
        m_isRunning(false)
{
}

Server::~Server()
{
    stop();
}

void Server::start()
{
    if (m_isRunning) {
        return; // Server is already running
    }
    m_isRunning = true;
    m_acceptThread = std::thread(&Server::acceptConnections, this);
}

void Server::stop()
{
    m_isRunning = false;
    m_listener.stopListening(); // Stop the listener from accepting new connections

    if (m_acceptThread.joinable()) {
        m_acceptThread.join();
    }
}

void Server::acceptConnections()
{
    while (m_isRunning)
    {
        Socket clientSocket = m_connectionAcceptor.acceptConnection();
        if (!clientSocket.isValid())
        {
           if (!m_isRunning) {
                break; // Exit the loop if the server is stopping
            }
            int error = clientSocket.getLastError();
            continue; // Continue accepting new connections 
        }
        handleClient(std::move(clientSocket));
    }
}

void Server::handleClient(Socket socket)
{
}