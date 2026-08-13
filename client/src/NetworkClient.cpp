#include "NetworkClient.h"

NetworkClient::NetworkClient()
    : m_socket(),
      m_sender(m_socket),
      m_receiver(m_socket,
                [this](const Message& message) 
                { onMessageReceived(message); }),
      m_connectionState(ConnectionState::DISCONNECTED)
{
}

NetworkClient::~NetworkClient()
{
    disconnect();
}

bool NetworkClient::connect(const std::string &ip, unsigned short port)
{
    if (m_connectionState != ConnectionState::DISCONNECTED)
    {
        return false; // Already connected or in the process of connecting
    }

    m_connectionState = ConnectionState::CONNECTING;

    if (!m_socket.create())
    {
        m_connectionState = ConnectionState::DISCONNECTED;
        return false; // Failed to create socket
    }

    if (!m_socket.connect(ip, port))
    {
        m_socket.close();
        m_connectionState = ConnectionState::DISCONNECTED;
        return false; // Failed to connect
    }

    m_connectionState = ConnectionState::CONNECTED;

    // Start the receiving thread
    m_receiveThread = std::thread(&Receiver::receiveLoop, &m_receiver);

    return true;
}

void NetworkClient::disconnect()
{
    if (m_connectionState != ConnectionState::CONNECTED)
    {
        return; // Not connected
    }

    m_connectionState = ConnectionState::DISCONNECTING;

    // Stop the receiver
    m_receiver.stop();

    // Shutdown the socket for sending and receiving
    m_socket.shutdown();

    // Wait for the receiving thread to finish
    if (m_receiveThread.joinable())
    {
        m_receiveThread.join();
    }

    // Close the socket
    m_socket.close();

    m_connectionState = ConnectionState::DISCONNECTED;
}

bool NetworkClient::sendMessage(const Message &message)
{
    if (m_connectionState != ConnectionState::CONNECTED)
    {
        return false; // Not connected
    }
    return m_sender.sendMessage(message);
}

void NetworkClient::setMessageCallback(MessageCallback callback)
{
    m_messageCallback = callback;
}

void NetworkClient::onMessageReceived(const Message &message)
{
    if (m_messageCallback)
    {
        m_messageCallback(message);
    }
}

ConnectionState NetworkClient::getConnectionState() const
{
    return m_connectionState;
}