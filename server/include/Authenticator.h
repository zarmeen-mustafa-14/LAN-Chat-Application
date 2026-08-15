#pragma once

#include <vector>

#include "User.h"
#include "Message.h"

struct AuthenticationResult
{
    bool success;
    User user; // User information if authentication is successful
};

class Authenticator
{
    private:
        std::vector<User> m_users; // List of users for authentication

        // helper functions used by authenticate() for cleaner code
        const User* findUserByUsername(const std::string& username) const;
        const User* findUserById(unsigned int userId) const;
        bool verifyPassword(const User& user, const std::string& password) const;
    public:
        // Constructor
        Authenticator();

        // Authenticate a user based on the provided username and password
        AuthenticationResult authenticate(const Message& message) const;
};