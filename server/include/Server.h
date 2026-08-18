#pragma once
#include <thread>
#include <atomic>

#include "WinSockinitializer.h"
#include "ClientManager.h"
#include "ConnectionAcceptor.h"
#include "Listener.h"
#include "Authenticator.h"

class Server {
    private: 
        // Member variables
        WinSockInitializer m_winSockInitializer;
        Listener m_listener;
        ConnectionAcceptor m_connectionAcceptor;
        Authenticator m_authenticator;
        ClientManager m_clientManager;
        std::atomic<bool> m_isRunning;
        std::thread m_acceptThread; // Thread for accepting connections

        // Private functions
        void acceptConnections();

        void handleClient(Socket socket);

    public:
        Server();
        ~Server();

        void start();
        void stop();
};