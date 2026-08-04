#include "Message.h"
Message::Message(Protocol::MessageType type, const std::string &senderName, const std::string &content, time_t timestamp, const std::string &recipientName, const std::string& password): type(type), senderName(senderName), content(content), timestamp(timestamp), recipientName(recipientName), password(password) {}
Protocol::MessageType Message::getType() const{
    return type;
}
std::string Message::getSenderName() const{
    return senderName;
}
std::string Message::getContent() const{
    return content;
}
std::string Message::getRecipientName() const{
    return recipientName;
}
time_t Message::getTimestamp() const{
    return timestamp;
}
std::string Message::getPassword() const{
    return password;
}