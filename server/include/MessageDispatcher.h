#ifndef MESSAGE_DISPATCHER_H
#define MESSAGE_DISPATCHER_H

#include "Message.h"

class Broadcaster;

class MessageDispatcher {
private:
    Broadcaster& broadcaster;
public:
    MessageDispatcher(Broadcaster& broadcaster);
    void handle(const Message& message);
};

#endif