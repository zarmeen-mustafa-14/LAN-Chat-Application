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
    m_isRunning = true;
}

void Server::stop()
{
    m_isRunning = false;
}

void Server::acceptConnections()
{
    while (m_isRunning)
    {
        Socket clientSocket = m_connectionAcceptor.acceptConnection();
        if (!clientSocket.isValid())
        {
           if (m_isRunning) {
                // Log the error if the server is still running
                int errorCode = WSAGetLastError();
            }
            continue; // Continue accepting new connections 
        }
        handleClient(std::move(clientSocket));
    }
}

void Server::handleClient(Socket socket)
{
}