#pragma once

#include "Socket.h"
#include "User.h"

struct AuthenticationResult
{
    bool success;
    User user; // User information if authentication is successful
};

class Authenticator
{

    public:
        // Authenticate a user based on the provided username and password
        static AuthenticationResult authenticate(Socket& socket);
};