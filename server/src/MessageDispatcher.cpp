#include "MessageDispatcher.h"
#include "Broadcaster.h"

MessageDispatcher::MessageDispatcher(Broadcaster &broadcaster) : broadcaster(broadcaster) {}

void MessageDispatcher::handle(const Message &message)
{
    switch (message.getType())
    {
    case Protocol::MessageType::CHAT:
        broadcaster.broadcastToAll(message);
        break;
    case Protocol::MessageType::PRIVATE:
        broadcaster.sendToOne(message, message.getRecipientName());
        break;
    case Protocol::MessageType::LEAVE:
        broadcaster.broadcastToAll(message);
        break;

    default:
        // SIGNUP/LOGIN/AUTH_SUCCESS/AUTH_FAIL/SYSTEM shouldn't reach here, handled earlier in ClientSession's auth stage, not the normal message loop
        break;
    }
}