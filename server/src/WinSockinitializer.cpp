#include "include/WinSockInitializer.h"

#include <winsock2.h>
#include <stdexcept>
#include <string>

WinSockInitializer :: WinSockInitializer()
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        throw std::runtime_error("WSAStartup failed with error: " + std::to_string(result));
    }
}

WinSockInitializer :: ~WinSockInitializer()
{
    WSACleanup();
}