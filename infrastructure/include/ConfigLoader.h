#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#include <string>
#include "Config.h"

class ConfigLoader{
    public:
    
    static Config load(const std::string& filePath);
};
#endif