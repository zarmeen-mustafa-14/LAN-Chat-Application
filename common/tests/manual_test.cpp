#include "Message.h"
#include "Serializer.h"
#include <iostream>
#include <ctime>

int main()
{
    time_t now = time(nullptr);

    Message chatMsg(Protocol::MessageType::CHAT, "Bob", "hello everyone", now);
    std::cout << "[CHAT] " << chatMsg.getSenderName() << ": " << chatMsg.getContent()
              << " (timestamp: " << chatMsg.getTimestamp() << ")" << std::endl;

    Message privateMsg(Protocol::MessageType::PRIVATE, "Bob", "hey, just for you", now, "Alice");
    std::cout << "[PRIVATE] " << privateMsg.getSenderName()
              << " -> " << privateMsg.getRecipientName()
              << ": " << privateMsg.getContent()
              << " (timestamp: " << privateMsg.getTimestamp() << ")" << std::endl;
    std::string wireFormat = Serializer::serialize(privateMsg);
    std::cout << "[SERIALIZED] " << wireFormat << std::endl;
    return 0;
}