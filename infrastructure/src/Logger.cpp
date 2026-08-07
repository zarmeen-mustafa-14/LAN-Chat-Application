#include "Logger.h"

Logger::Logger(LogSink& sink):sink(sink){}

std::string Logger::levelToString(LogLevel level){
    switch (level)
    {
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARNING:
        return "WARNING";
    case LogLevel::ERROR:
        return "ERROR";
    }
    return "UNKNOWN";
}

void Logger::log(LogLevel level, const std::string& message){
    std::string formatted = "[" + levelToString(level) + "] " + message;
    sink.write(formatted); 
}