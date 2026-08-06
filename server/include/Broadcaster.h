#ifndef BROADCASTER_H
#define BROADCASTER_H

#include <string>
#include "Message.h"

class ClientManager;
class ClientSession;

class Broadcaster{
    private:
    ClientManager& clientManager;
    public:
    // Constructor 
    Broadcaster(ClientManager& clientManager);

    // Functions to be used in MessageDispatcher 
    void broadcastToAll(const Message& message);
    void sendToOne(const Message& message, const std::string& recipientUserName);
};
#endif