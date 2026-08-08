#include "ConsoleUI.h"
#include <iostream>
#include <ctime>

// Displays normal CHAT messages
void ConsoleUI::displayChatMessage(const std::string &sender, const std::string &content, time_t timestamp)
{
    std::cout << "[" << formatTimestamp(timestamp) << "] " << sender << ": " << content << std::endl;
}

// Displays PRIVATE Messages sent by other Clients 
void ConsoleUI::displayPrivateMessage(const std::string &sender, const std::string &content, time_t timestamp)
{
    std::cout << "[" << formatTimestamp(timestamp) << "] (whisper) " << sender << ": " << content << std::endl;
}

// Displays message sent by the Server itself 
void ConsoleUI::displaySystemMessage(const std::string &content)
{
    std::cout << "*** " << content << " ***" << std::endl;
}

// Converts time_t type timestamp to a formatted human readable string 
std::string ConsoleUI::formatTimestamp(time_t timestamp) const{
    char buffer[9]; // "HH:MM:SS" + Null Terminator
    struct tm* timeInfo = localtime(&timestamp);
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeInfo);
    return std::string(buffer);
}

// Returns false when the input is not starting with "/whisper" else returns true 
bool ConsoleUI::tryParseWhisperCommand(const std::string &input, std::string &recipient, std::string &content) const{
    const std::string prefix = "/whisper ";
    if (input.size() <= prefix.size() || input.substr(0, prefix.size()) != prefix)
    {
        return false; // Either the input message is smaller than our prefix or te initial word is not our prefix that is why we are returning false
    }

    // Removed the prefix from the original input 
    std::string remainder = input.substr(prefix.size());

    size_t spacePos = remainder.find(" "); // Found the position at which the recipient name's end and content starts and stored in spacPos
    if (spacePos == std::string::npos)
    {
        return false; // No content after the recipient name 
    }

    recipient = remainder.substr(0, spacePos);
    content = remainder.substr(spacePos + 1);
    return true;
}

// Takes username of the sender as an argument and then internally takes an input from the user and returns a Message of type either CHAT or PRIVATE depending upon whether the user typed "/whisper" followed by recipient name for PRIVATE message or not 
Message ConsoleUI::readUserInput(const std::string& myUsername){
    // Declaring an input variable and taking input from the user 
    std::string input; 
    std::getline(std::cin, input);

    // Declaring recipient and content variables to be initialized by tryParseWhisperCommand() in the case of PRIVATE message 
    std::string recipient, content;
    if (tryParseWhisperCommand(input, recipient, content))
    {
        return Message(Protocol::MessageType::PRIVATE, myUsername, content, time(nullptr), recipient);
    }
    
    // Returning a Message contructed when the input was not a PRIVATE type 
    return Message(Protocol::MessageType::CHAT, myUsername, input, time(nullptr));
}