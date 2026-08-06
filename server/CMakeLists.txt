add_executable(Server)

target_sources(Server
    PRIVATE
        src/main.cpp
        src/ClientSession.cpp
        src/MessageDispatcher.cpp
        src/Broadcaster.cpp
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