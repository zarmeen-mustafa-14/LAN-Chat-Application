#include "ClientMessageDispatcher.h"
#include "ConsoleUI.h"

ClientMessageDispatcher::ClientMessageDispatcher(ConsoleUI &consoleUI) : consoleUI(consoleUI) {}

void ClientMessageDispatcher::handle(const Message &message)
{
    switch (message.getType())
    {
    case Protocol::MessageType::CHAT:
        consoleUI.displayChatMessage(message.getSenderName(), message.getContent(), message.getTimestamp());
        break;
    case Protocol::MessageType::PRIVATE:
        consoleUI.displayPrivateMessage(message.getSenderName(), message.getContent(), message.getTimestamp());
        break;
    case Protocol::MessageType::SYSTEM:
        // Fall Through
    case Protocol::MessageType::AUTH_FAIL:
        consoleUI.displaySystemMessage(message.getContent());
        break;
    case Protocol::MessageType::LEAVE:
        consoleUI.displaySystemMessage(message.getSenderName() + " has left the chat!");
        break;

    default:
        // SIGNUP/LOGIN/AUTH_SUCCESS shouldn't normally arrive here as incoming messages to display — they're part of the outgoing auth handshake, not something the server broadcasts back for display purposes (AUTH_SUCCESS might just trigger the client to proceed, not print anything)
        break;
    }
}