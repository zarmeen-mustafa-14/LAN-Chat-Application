#ifndef LOG_SINK_H
#define LOG_SINK_H

#include <string>
// It is a Abstract class so that later on depending upon the type of message we can write it differently
class LogSink{
    public:
    // Pure virtual function used for runtime polymorphism later on
    virtual void write(const std::string& message) = 0;

    // Virtual destructor for safe cleanup
    virtual ~LogSink(){}
};
#endif