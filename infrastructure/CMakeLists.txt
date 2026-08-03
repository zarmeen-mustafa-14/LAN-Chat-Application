add_library(Infrastructure STATIC)

target_sources(Infrastructure
    PRIVATE
        src/ConsoleLogSink.cpp
)

target_include_directories(Infrastructure
    PUBLIC
        include
)