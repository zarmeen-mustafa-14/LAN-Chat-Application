#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <cstddef>
namespace Protocol
{
    enum class MessageType
    {
        SIGNUP,
        LOGIN,
        AUTH_SUCCESS,
        AUTH_FAIL,
        CHAT,
        LEAVE,
        PRIVATE
    };
    constexpr char DELIMITER = '\n';
    constexpr char FIELD_SEPARATOR = '|';
    constexpr size_t MAX_MESSAGE_LENGTH = 1024;
}

#endif