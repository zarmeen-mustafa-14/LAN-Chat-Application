#include "Broadcaster.h"
#include "ClientManager.h"
#include "ClientSession.h"
#include "Client.h"

Broadcaster::Broadcaster(ClientManager& clientManager):clientManager(clientManager){}

void Broadcaster::broadcastToAll(const Message& message){
    std::vector<Client*> clients = clientManager.getAllClients();
    for(Client* client : clients){
        ClientSession* session = clientManager.getSession(client->getUserId());
        if (session != nullptr)
        {
            session->sendMessage(message);
        }
    }
}

void Broadcaster::sendToOne(const Message& message, const std::string& recipientUserName){
    Client* client = clientManager.getClientByUsername(recipientUserName);
    if (client == nullptr) {
        return; // recipient not found — could notify sender here later
    }
    ClientSession* session = clientManager.getSession(client->getUserId());
    if (session != nullptr)
    {
        session->sendMessage(message);
    }
    
}