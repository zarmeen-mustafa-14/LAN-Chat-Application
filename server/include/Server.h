#pragma once

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
        bool m_isRunning;

        // Private functions
        void acceptConnections();

        void handleClient(Socket socket);

    public:
        Server();
        ~Server();

        void start();
        void stop();
};