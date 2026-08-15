#include "Authenticator.h"

Authenticator::Authenticator()
{
    // Initialize the list of users for authentication
    m_users.push_back({1, "user1", "password1"});
    m_users.push_back({2, "user2", "password2"});
}

const User* Authenticator::findUserByUsername(const std::string& username) const
{
    for (const auto& user : m_users)
    {
        if (user.username == username)
        {
            return &user;
        }
    }
    return nullptr; // User not found
}

const User* Authenticator::findUserById(unsigned int userId) const
{
    for (const auto& user : m_users)
    {
        if (user.userId == userId)
        {
            return &user;
        }
    }
    return nullptr; // User not found
}

bool Authenticator::verifyPassword(const User& user, const std::string& password) const
{
    return user.password == password; // In a real application, consider hashing and salting the password
}

AuthenticationResult Authenticator::authenticate(const Message& message) const
{
    const User* user = findUserByUsername(message.getSenderName());
    user = user ? findUserById(user->userId) : nullptr; // Ensure to have the user by ID as well

    if (user == nullptr)
    {
        return { false, User() }; // User not found
    }

    if (user && verifyPassword(*user, message.getPassword()))
    {
        return { true, *user };
    }
    return { false, User() }; // Return a default User object on failure
}