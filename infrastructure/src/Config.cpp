#include "Config.h"

// Constructor 
Config::Config(unsigned short port, const std::string& bindAddress):port(port), bindAddress(bindAddress){}

// Getters 
unsigned short Config::getPort() const{
    return port;
}

std::string Config::getBindAddress() const{
    return bindAddress;
}