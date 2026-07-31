#include "MessageValidator.h"
bool MessageValidator::isContentLengthValid(const Message &message)
{
    return message.getContent().length() <= Protocol::MAX_MESSAGE_LENGTH;
}
bool MessageValidator::isSenderNameValid(const Message &message)
{
    return !message.getSenderName().empty();
}
bool MessageValidator::isRecipientValid(const Message &message)
{
    if (message.getType() == Protocol::MessageType::PRIVATE)
    {
        return !message.getRecipientName().empty();
    }
    return true;
}
bool MessageValidator::isValid(const Message &message)
{
    return isContentLengthValid(message) && isSenderNameValid(message) && isRecipientValid(message);
}
std::string MessageValidator::getRejectionReason(const Message &message)
{
    if (!isContentLengthValid(message))
    {
        return "Message content exceeds maximum allowed length";
    }
    if (!isSenderNameValid(message))
    {
        return "Message sender name cannot be empty";
    }
    if (!isRecipientValid(message))
    {
        return "Private messages must specify a recipient";
    }
    return "";
}