#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <string>
#include "Message.h"
class Serializer
{
private:
    static std::string typeToString(Protocol::MessageType type);
    static std::string escapeField(const std::string& field);

public:
    static std::string serialize(const Message &message);
};
#endif