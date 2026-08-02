#ifndef MESSAGE_H
#define MESSAGE_H
#include "Protocol.h"
#include <string>
#include <ctime>
class Message
{
private:
    Protocol::MessageType type;
    std::string senderName;
    std::string content;
    std::string recipientName;
    time_t timestamp;

public:
    Message(Protocol::MessageType type, const std::string &senderName, const std::string &content,time_t timestamp, const std::string &recipientName ="");
    Protocol::MessageType getType() const;
    std::string getSenderName() const;
    std::string getContent() const;
    std::string getRecipientName() const;
    time_t getTimestamp() const;
};
#endif