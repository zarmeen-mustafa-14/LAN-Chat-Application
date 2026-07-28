add_library(Infrastructure STATIC)

target_sources(Infrastructure
    PRIVATE
        src/dummy.cpp
)

target_include_directories(Infrastructure
    PUBLIC
        include
)