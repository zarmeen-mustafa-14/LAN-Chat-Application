add_library(Infrastructure STATIC)

target_sources(Infrastructure
    PRIVATE
        src/ConsoleLogSinkcpp
)

target_include_directories(Infrastructure
    PUBLIC
        include
)