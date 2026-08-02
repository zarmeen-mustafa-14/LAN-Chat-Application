add_library(Common STATIC)

target_sources(Common
    PRIVATE
        src/Message.cpp
        src/Parser.cpp
        src/Serializer.cpp
        src/MessageValidator.cpp
)

target_include_directories(Common
    PUBLIC
        include
)