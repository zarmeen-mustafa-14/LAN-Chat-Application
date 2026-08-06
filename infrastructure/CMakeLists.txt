add_library(Infrastructure STATIC)

target_sources(Infrastructure
    PRIVATE
        src/ConsoleLogSink.cpp
        src/Socket.cpp
        src/WinSockInitializer.cpp
)

target_include_directories(Infrastructure
    PUBLIC
        include
)

target_link_libraries(Infrastructure
    PUBLIC
        ws2_32
)