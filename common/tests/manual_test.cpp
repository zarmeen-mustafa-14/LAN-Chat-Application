#include "Message.h"
#include "Serializer.h"
#include "Parser.h"
#include "MessageValidator.h"
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

    Message validMsg(Protocol::MessageType::CHAT, "Bob", "hello", now);
    std::cout << "[VALID CHECK] valid message: " << MessageValidator::isValid(validMsg) << std::endl;

    Message emptyPrivate(Protocol::MessageType::PRIVATE, "Bob", "secret", now); // no recipient given, defaults to ""
    std::cout << "[VALID CHECK] private w/o recipient: " << MessageValidator::isValid(emptyPrivate) << std::endl;
    std::cout << "[REASON] " << MessageValidator::getRejectionReason(emptyPrivate) << std::endl;

    Message noSender(Protocol::MessageType::CHAT, "", "hello", now);
    std::cout << "[VALID CHECK] empty sender: " << MessageValidator::isValid(noSender) << std::endl;
    std::cout << "[REASON] " << MessageValidator::getRejectionReason(noSender) << std::endl;

    std::string longContent(Protocol::MAX_MESSAGE_LENGTH + 50, 'x'); // 50 characters over the limit
    Message tooLong(Protocol::MessageType::CHAT, "Bob", longContent, now);
    std::cout << "[VALID CHECK] too long message: " << MessageValidator::isValid(tooLong) << std::endl;
    std::cout << "[REASON] " << MessageValidator::getRejectionReason(tooLong) << std::endl;

    std::string exactContent(Protocol::MAX_MESSAGE_LENGTH, 'x'); // exactly at the limit
    Message exactSize(Protocol::MessageType::CHAT, "Bob", exactContent, now);
    std::cout << "[VALID CHECK] exactly at limit: " << MessageValidator::isValid(exactSize) << std::endl;

    // Test SIGNUP message with password
    Message signupMsg(Protocol::MessageType::SIGNUP, "Bob", "", now, "", "mySecretPass123");
    std::string wireFormatSignup = Serializer::serialize(signupMsg);
    std::cout << "[SERIALIZED SIGNUP] " << wireFormatSignup << std::endl;

    Message parsedSignup = Parser::parse(wireFormatSignup);
    std::cout << "[PARSED SIGNUP] username: " << parsedSignup.getSenderName()
              << ", password: " << parsedSignup.getPassword()
              << ", type: " << (parsedSignup.getType() == Protocol::MessageType::SIGNUP ? "SIGNUP" : "WRONG")
              << std::endl;

    // Validation checks for password rule
    std::cout << "[VALID CHECK] signup with password: " << MessageValidator::isValid(signupMsg) << std::endl;

    Message signupNoPassword(Protocol::MessageType::SIGNUP, "Alice", "", now, "", "");
    std::cout << "[VALID CHECK] signup without password: " << MessageValidator::isValid(signupNoPassword) << std::endl;
    std::cout << "[REASON] " << MessageValidator::getRejectionReason(signupNoPassword) << std::endl;
    return 0;
}