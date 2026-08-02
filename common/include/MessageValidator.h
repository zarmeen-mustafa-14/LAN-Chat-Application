#ifndef MESSAGE_VALIDATOR_H
#define MESSAGE_VALIDATOR_H
#include <string>
#include "Message.h"
class MessageValidator{
    private:
    static bool isContentLengthValid(const Message& message);
    static bool isSenderNameValid(const Message& message);
    static bool isRecipientValid(const Message& message);
    public:
    static bool isValid(const Message& message);
    static std::string getRejectionReason(const Message& message);
};
#endif