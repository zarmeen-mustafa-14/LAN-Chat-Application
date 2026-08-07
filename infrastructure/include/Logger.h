#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include "LogSink.h"

enum class LogLevel{
    INFO,
    WARNING,
    ERROR
};

class Logger{
    private:
    // A reference of interface LogSink held to acheive runtime polymorphism
    LogSink& sink;

    // Helper function to convert LogLevel type to string 
    static std::string levelToString(LogLevel level);
    public:
    // Constructor 
    Logger(LogSink& sink);
    
    // Main log function that is going to be used by other classes 
    void log(LogLevel level, const std::string& message);
    
};
#endif