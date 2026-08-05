add_executable(Client)

target_sources(Client
    PRIVATE
        src/main.cpp
        # src/Sender.cpp
        # src/Receiver.cpp
        # src/NetworkClient.cpp
)

target_include_directories(Client
    PRIVATE
        include
)

target_link_libraries(Client
    PRIVATE
        Common
        Infrastructure
)