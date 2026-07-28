add_library(Common STATIC)

target_sources(Common
    PRIVATE
        Message.cpp
        Parser.cpp
        Serializer.cpp
)

target_include_directories(Common
    PUBLIC
        include
)