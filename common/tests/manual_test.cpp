#include "../Message.h"
#include "../Serializer.h"
#include "../Parser.h"
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
    Message parsedBack = Parser::parse(wireFormat);
    std::cout << "[PARSED BACK] " << parsedBack.getSenderName()
              << " -> " << parsedBack.getRecipientName()
              << ": " << parsedBack.getContent()
              << " (timestamp: " << parsedBack.getTimestamp() << ")" << std::endl;
    Message trickyMsg(Protocol::MessageType::CHAT, "Bob", "price is $5|10 total", now);
    std::string wireFormat2 = Serializer::serialize(trickyMsg);
    std::cout << "[SERIALIZED TRICKY] " << wireFormat2 << std::endl;

    Message parsedTricky = Parser::parse(wireFormat2);
    std::cout << "[PARSED TRICKY] content: " << parsedTricky.getContent() << std::endl;

    Message backslashMsg(Protocol::MessageType::CHAT, "Bob", "path is C:\\Users\\Bob", now);
    std::string wireFormat3 = Serializer::serialize(backslashMsg);
    std::cout << "[SERIALIZED BACKSLASH] " << wireFormat3 << std::endl;

    Message parsedBackslash = Parser::parse(wireFormat3);
    std::cout << "[PARSED BACKSLASH] content: " << parsedBackslash.getContent() << std::endl;
    return 0;
}