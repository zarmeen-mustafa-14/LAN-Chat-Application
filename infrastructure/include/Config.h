#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

class Config{
    private:
    unsigned short port;
    std::string bindAddress;

    public:
    // Constructor 
    Config(unsigned short port, const std::string& bindAddress);

    // Getters 
    unsigned short getPort() const;
    std::string getBindAddress() const;
};

#endif