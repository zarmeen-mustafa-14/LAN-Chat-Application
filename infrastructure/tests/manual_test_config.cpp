#include "ConfigLoader.h"
#include <iostream>

int main() {
    Config config = ConfigLoader::load("config.txt");
    std::cout << "Port: " << config.getPort() << std::endl;
    std::cout << "Bind address: " << config.getBindAddress() << std::endl;
    return 0;
}