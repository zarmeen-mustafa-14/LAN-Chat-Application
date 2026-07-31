#ifndef PARSER_H
#define PARSER_H
#include<vector>
#include<string>
#include "Message.h"
class Parser{
    private:
    static Protocol::MessageType stringToType(const std::string& typeStr);
    static std::vector<std::string> splitFields(const std::string& raw, char separator);
    public:
    static Message parse(const std::string& raw);
};
#endif