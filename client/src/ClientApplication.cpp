#include "ClientApplication.h"
#include <iostream>
#include <ctime>

ClientApplication::ClientApplication():clientMessageDispatcher(consoleUi){
    networkClient.setMessageCallback([this](const Message& message){
        onIncomingMessage(message);
    });
}

void ClientApplication::onIncomingMessage(const Message& message){
    if (message.getType()==Protocol::MessageType::AUTH_SUCCESS || message.getType()==Protocol::MessageType::AUTH_FAIL)
    {
      {
        std::lock_guard<std::mutex> lock(authMutex);
        authState = (message.getType() == Protocol::MessageType::AUTH_SUCCESS) ? AuthState::SUCCESS: AuthState::FAILED;
        authFailReason = message.getContent();
      }
      authCV.notify_one();
      return;
    }
    clientMessageDispatcher.handle(message);
}

bool ClientApplication::authenticate(bool isSignup){
    // Checking the message type to make afterwards 
    Protocol::MessageType authType = isSignup ? Protocol::MessageType::SIGNUP : Protocol::MessageType::LOGIN;

    // Taking username and password from the user 
    std::cout<<"Username: ";
    std::getline(std::cin, myUsername);

    std::cout<<"Password: ";
    std::string password;
    std::getline(std::cin, password);

    // Locking the thread to modify authState because it is a shared variable between two threads and modifying it needs a lock for data integrity
    {
        std::lock_guard<std::mutex> lock(authMutex);
        authState = AuthState::PENDING;
    }

    // Constructing an authentication message to send over the server for authentication 
    Message authMessage = Message(authType, myUsername, "", time(nullptr), "", password);
    if (!networkClient.sendMessage(authMessage))
    {
        std::cout<<"Failed to send authentication request!!!"<<std::endl;
        return false;
    }

    // Putting our thread to sleep until the server deals with the authentication message sent by modifying the shared authState variable and in case of no response thread will wait till 10 seconds 
    std::unique_lock<std::mutex> lock(authMutex);
    bool arrived = authCV.wait_for(lock, std::chrono::seconds(10), [this]{return authState != AuthState::PENDING;});

    // Checking if the thread woke up because of server's response or 10 seconds timed it out 
    if(!arrived)
    {
        std::cout<<"Authentication timed out!!!"<<std::endl;
        return false;
    }
    
    // In case of server's response logging the respective reply  
    if (authState == AuthState::SUCCESS)
    {
        std::cout<<"Authenticated successfully!!!"<<std::endl;
        return true;
    }
    else{
        std::cout<<"Authentication failed: "<<authFailReason<<std::endl;
        return false;
    }
}

// Takes IP and Port and try to connect with the server and takes from user whether they want to Login or Signup and then authenticate it accordingly
bool ClientApplication::start(const std::string& ip, unsigned short port){
    if (!networkClient.connect(ip, port)) {
        std::cout << "Could not connect to server." << std::endl;
        return false;
    }

    std::cout << "1. Login\n2. Sign up\nChoose: ";
    std::string choice;
    std::getline(std::cin, choice);

    return authenticate(choice == "2");
}

// Runs the sending loop until the connection gets dropped 
void ClientApplication::run(){
    while (networkClient.getConnectionState() == ConnectionState::CONNECTED)
    {
        Message toSend = consoleUi.readUserInput(myUsername);
        networkClient.sendMessage(toSend);
    }
}