#pragma once

#include <string>

struct User
{
    unsigned int userId; // Unique identifier for the user
    std::string username; // Username of the user
    std::string password; // Password of the user (consider hashing in a real application)
};