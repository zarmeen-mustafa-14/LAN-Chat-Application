#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>

class WinSockInitializer
{
public:
    // Constructor and Destructor
    WinSockInitializer();
    ~WinSockInitializer();

    // Prevent copying
    WinSockInitializer(const WinSockInitializer&) = delete;
    WinSockInitializer& operator=(const WinSockInitializer&) = delete;

    // Prevent moving
    WinSockInitializer(WinSockInitializer&&) = delete;
    WinSockInitializer& operator=(WinSockInitializer&&) = delete;
};