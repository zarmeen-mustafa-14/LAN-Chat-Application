#include "ConsoleUI.h"
#include <iostream>
#include <ctime>

int main() {
    ConsoleUI ui;

    std::cout << "--- Testing display methods ---" << std::endl;
    time_t now = time(nullptr);
    ui.displayChatMessage("Bob", "hello everyone", now);
    ui.displayPrivateMessage("Alice", "hey, secret message", now);
    ui.displaySystemMessage("Bob has joined the chat");

    std::cout << "\n--- Testing input parsing ---" << std::endl;
    std::cout << "Type a plain message: ";
    Message chatResult = ui.readUserInput("TestUser");
    std::cout << "  type: " << (chatResult.getType() == Protocol::MessageType::CHAT ? "CHAT" : "OTHER")
              << ", content: \"" << chatResult.getContent() << "\""
              << ", recipient: \"" << chatResult.getRecipientName() << "\"" << std::endl;

    std::cout << "\nType a whisper (e.g. /whisper Bob hi there): ";
    Message privateResult = ui.readUserInput("TestUser");
    std::cout << "  type: " << (privateResult.getType() == Protocol::MessageType::PRIVATE ? "PRIVATE" : "OTHER")
              << ", content: \"" << privateResult.getContent() << "\""
              << ", recipient: \"" << privateResult.getRecipientName() << "\"" << std::endl;

    std::cout << "\nType /whisper with no message (e.g. /whisper Bob): ";
    Message edgeCaseResult = ui.readUserInput("TestUser");
    std::cout << "  type: " << (edgeCaseResult.getType() == Protocol::MessageType::PRIVATE ? "PRIVATE" : "CHAT (fallback)")
              << ", content: \"" << edgeCaseResult.getContent() << "\"" << std::endl;

    return 0;
}