#include "ClientSession.h"
#include "Serializer.h"
#include "Parser.h"
#include "MessageValidator.h"
#include "ClientManager.h"
#include "MessageDispatcher.h"
#include "Authenticator.h"
#include <ctime>
#include <stdexcept>

ClientSession::ClientSession(Socket &&socket, unsigned int userId)
    : socket(std::move(socket)), userId(userId), connected(true)
{
}

void ClientSession::run(ClientManager &clientManager, MessageDispatcher &dispatcher, Authenticator &authenticator)
{
    // Step 1: authenticate
    std::string raw;
    if (!socket.receive(raw))
    {
        disconnect();
        return;
    }

    try
    {
        Message authMessage = Parser::parse(raw);

        if (!MessageValidator::isValid(authMessage))
        {
            Message failMsg(Protocol::MessageType::AUTH_FAIL, "Server",
                            MessageValidator::getRejectionReason(authMessage), time(nullptr));
            sendMessage(failMsg);
            disconnect();
            return;
        }

        AuthenticationResult result = authenticator.authenticate(authMessage);

        if (!result.success)
        {
            Message failMsg(Protocol::MessageType::AUTH_FAIL, "Server", "Authentication failed", time(nullptr));
            sendMessage(failMsg);
            disconnect();
            return;
        }
    }
    catch (const std::invalid_argument &e)
    {
        Message failMsg(Protocol::MessageType::AUTH_FAIL, "Server",
                        std::string("Malformed authentication message: ") + e.what(), time(nullptr));
        sendMessage(failMsg);
        disconnect();
        return;
    }

    // Step 2: main message loop
    while (connected)
    {
        std::string rawMsg;
        if (!socket.receive(rawMsg))
        {
            disconnect();
            break;
        }

        try
        {
            Message message = Parser::parse(rawMsg);

            if (MessageValidator::isValid(message))
            {
                dispatcher.handle(message);
            }
            else
            {
                Message rejectMsg(Protocol::MessageType::SYSTEM, "Server",
                                  MessageValidator::getRejectionReason(message), time(nullptr));
                sendMessage(rejectMsg);
            }
        }
        catch (const std::invalid_argument &e)
        {
            Message rejectMsg(Protocol::MessageType::SYSTEM, "Server",
                              std::string("Malformed message: ") + e.what(), time(nullptr));
            sendMessage(rejectMsg);
            // no return/break — loop continues to wait for the next message
        }
    }
}

void ClientSession::sendMessage(const Message &message)
{
    std::string wireFormat = Serializer::serialize(message);
    socket.send(wireFormat);
}

void ClientSession::disconnect()
{
    connected = false;
    socket.close();
}

bool ClientSession::isConnected() const
{
    return connected;
}