#ifndef CLIENT_APPLICATION_H
#define CLIENT_APPLICATION_H

#include <string>
#include <mutex>
#include <condition_variable>
#include "NetworkClient.h"
#include "ClientMessageDispatcher.h"
#include "ConsoleUI.h"

enum class AuthState{
    PENDING,
    SUCCESS,
    FAILED
};

class ClientApplication{
    private:
    NetworkClient networkClient;
    ConsoleUI consoleUi;
    ClientMessageDispatcher clientMessageDispatcher;
    std::string myUsername;

    std::mutex authMutex;
    std::condition_variable authCV;
    AuthState authState;
    std::string authFailReason;

    void onIncomingMessage(const Message& message); // A callback function which will be called by Receiver when any message is received.
    bool authenticate(bool isSignup); // handles SIGNUP/LOGIN exchange with the server.

    public:
    // Constructor 
    ClientApplication();

    bool start(const std::string& ip, unsigned short port);
    void run();
};

#endif