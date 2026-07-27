#include "Serializer.h"
std::string Serializer::typeToString(Protocol::MessageType type){
    switch (type)
    {
    case Protocol::MessageType::CHAT:
        return "CHAT";
        break;
    case Protocol::MessageType::JOIN:
        return "JOIN";
        break;
    case Protocol::MessageType::LEAVE:
        return "LEAVE";
        break;
    case Protocol::MessageType::PRIVATE:
        return "PRIVATE";
        break;
    }
    return "UNKNOWN";
}

std::string Serializer::serialize(const Message &message){
    std::string result;

    result += typeToString(message.getType());
    result += Protocol::FIELD_SEPARATOR;

    result += message.getSenderName();
    result += Protocol::FIELD_SEPARATOR;

    result += message.getContent();
    result += Protocol::FIELD_SEPARATOR;

    result += std::to_string(message.getTimestamp());
    result += Protocol::FIELD_SEPARATOR;

    result += message.getRecipientName();

    return result;
}