add_executable(Server)

target_sources(Server
    PRIVATE
        src/main.cpp
        src/Socket.cpp
        src/WinSockInitializer.cpp
)

target_include_directories(Server
    PRIVATE
        include
)

target_link_libraries(Server
    PRIVATE
        Common
        Infrastructure
)