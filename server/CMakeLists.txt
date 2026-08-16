add_executable(Server)

target_sources(Server
    PRIVATE
        src/main.cpp
        src/ClientSession.cpp
        src/MessageDispatcher.cpp
        src/Broadcaster.cpp
        src/Listener.cpp
        src/ConnectionAcceptor.cpp
        src/Client.cpp
        src/ClientManager.cpp
        src/Authenticator.cpp
        src/Server.cpp
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