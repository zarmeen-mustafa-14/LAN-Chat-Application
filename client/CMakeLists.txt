add_executable(Client)

target_sources(Client
    PRIVATE
        src/main.cpp
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