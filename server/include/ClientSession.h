#ifndef CLIENT_SESSION_H
#define CLIENT_SESSION_H

#include "Message.h"
#include "Socket.h"

class ClientManager;
class MessageDispatcher;
class Authenticator;

class ClientSession{
    private:
    Socket socket;
    unsigned int userId;
    bool connected;
    public:
    ClientSession(Socket&& socket, unsigned int userId);

    void run(ClientManager& clientManager, MessageDispatcher& messageDispatcher, Authenticator& authenticator);
    void sendMessage(const Message& message);
    void disconnect();
    bool isConnected() const;
};
#endif