#ifndef CONSOLE_LOG_SINK_H
#define CONSOLE_LOG_SINK_H
#include "infrastructure/include/LogSink.h"
#include <iostream>
class ConsoleLogSink : public LogSink
{
public:
    void write(const std::string& message) override;
};
#endif