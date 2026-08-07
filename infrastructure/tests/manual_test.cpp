#include "Logger.h"
#include "ConsoleLogSink.h"

int main() {
    ConsoleLogSink consoleSink;
    Logger logger(consoleSink);

    logger.log(LogLevel::INFO, "Server started");
    logger.log(LogLevel::WARNING, "Message rejected: too long");
    logger.log(LogLevel::ERROR, "Failed to bind socket");

    return 0;
}