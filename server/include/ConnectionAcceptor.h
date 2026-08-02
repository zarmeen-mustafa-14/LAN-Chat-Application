#pragma once

#include <winsock2.h>
#include "Client.h"
#include "Listener.h"
class ConnectionAcceptor
{
private:
    Listener &m_listener; // Reference to the Listener object that manages the listening socket
public:
    // Constructor and Destructor
    ConnectionAcceptor(Listener &listener);
    ~ConnectionAcceptor();

    // Accept a new client connection
    Socket acceptConnection();
};  