#include "Serializer.h"
std::string Serializer::typeToString(Protocol::MessageType type)
{
    switch (type)
    {
    case Protocol::MessageType::SIGNUP:
        return "SIGNUP";
    case Protocol::MessageType::LOGIN:
        return "LOGIN";
    case Protocol::MessageType::AUTH_SUCCESS:
        return "AUTH_SUCCESS";
    case Protocol::MessageType::AUTH_FAIL:
        return "AUTH_FAIL";
    case Protocol::MessageType::SYSTEM:
        return "SYSTEM";
    case Protocol::MessageType::CHAT:
        return "CHAT";
    case Protocol::MessageType::LEAVE:
        return "LEAVE";
    case Protocol::MessageType::PRIVATE:
        return "PRIVATE";
    }
    return "UNKNOWN";
}
std::string Serializer::escapeField(const std::string &field)
{
    std::string result;
    for (char c : field)
    {
        if (c == '\\')
        {
            result += "\\\\";
        }
        else if (c == Protocol::FIELD_SEPARATOR)
        {
            result += '\\';
            result += Protocol::FIELD_SEPARATOR;
        }
        else
        {
            result += c;
        }
    }
    return result;
}
std::string Serializer::serialize(const Message &message)
{
    std::string result;

    result += typeToString(message.getType());
    result += Protocol::FIELD_SEPARATOR;

    result += escapeField(message.getSenderName());
    result += Protocol::FIELD_SEPARATOR;

    result += escapeField(message.getContent());
    result += Protocol::FIELD_SEPARATOR;

    result += std::to_string(message.getTimestamp());
    result += Protocol::FIELD_SEPARATOR;

    result += escapeField(message.getRecipientName());
    result += Protocol::FIELD_SEPARATOR;

    result += escapeField(message.getPassword());

    return result;
}