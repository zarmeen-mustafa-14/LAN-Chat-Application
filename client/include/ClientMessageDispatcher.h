#ifndef CLIENT_MESSAGE_DISPATCHER_H
#define CLIENT_MESSAGE_DISPATCHER_H

#include "Message.h"

class ConsoleUI;

class ClientMessageDispatcher{
    private:
    // A reference to the ConsoleUI class to use it's public functions
    ConsoleUI& consoleUI;
    public:
    // Constructor 
    ClientMessageDispatcher(ConsoleUI& consoleUI);

    // A complete function to handle the message passed to it depending upon the type
    void handle(const Message& message);
};
#endif