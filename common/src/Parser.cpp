#include "Parser.h"
#include <stdexcept>
std::vector<std::string> Parser::splitFields(const std::string &raw, char separator)
{
    std::vector<std::string> fields;
    std::string current;
    bool escaping = false;
    for (char c : raw)
    {
        if (escaping)
        {
            current += c;  // Taking the character literally
            escaping = false;
        }
        else if (c == '\\')
        {
            escaping = true;  // Now the next character has to be treated literally even if it is a separator
        }
        else if (c == separator)
        {
            fields.push_back(current);
            current.clear();
        }
        else
        {
            current += c;
        }
    }
    fields.push_back(current); // To push the last string as it does not follow a separator
    return fields;
}
Protocol::MessageType Parser::stringToType(const std::string &typeStr)
{
    if (typeStr == "CHAT")
    {
        return Protocol::MessageType::CHAT;
    }
    if (typeStr == "LEAVE")
    {
        return Protocol::MessageType::LEAVE;
    }
    if (typeStr == "JOIN")
    {
        return Protocol::MessageType::JOIN;
    }
    if (typeStr == "PRIVATE")
    {
        return Protocol::MessageType::PRIVATE;
    }
    throw std::invalid_argument("Unknown message type: " + typeStr);
}
Message Parser::parse(const std::string &raw)
{
    std::vector<std::string> fields = splitFields(raw, Protocol::FIELD_SEPARATOR);
    if (fields.size() != 5)
    {
        throw std::invalid_argument("Malformed message: expected 5 fields, got " + std::to_string(fields.size()));
    }
    Protocol::MessageType type = stringToType(fields[0]);
    std::string senderName = fields[1];
    std::string content = fields[2];
    time_t timestamp = static_cast<time_t>(std::stoll(fields[3]));
    std::string recipientName = fields[4];

    return Message(type, senderName, content, timestamp, recipientName);
}