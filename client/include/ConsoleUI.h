#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "Message.h"
#include <string>
#include <ctime>

class ConsoleUI
{
private:
    std::string formatTimestamp(time_t timestamp) const;
    bool tryParseWhisperCommand(const std::string &input, std::string &recipient, std::string &content) const;

public:
    // Takes a username as argument and internally takes a string from the user and checks whether it is a CHAT message or a PRIVATE one by looking for "/whisper" in the starting (for that uses the private function tryParseWhisperComman()) and then construct a Message from it   
    Message readUserInput(const std::string& myUsername);
    
    // Functions to be used by ClientMessageDispatcher
    void displayChatMessage(const std::string &sender, const std::string &content, time_t timestamp);
    void displayPrivateMessage(const std::string &sender, const std::string &content, time_t timestamp);
    void displaySystemMessage(const std::string &content);
};
#endif