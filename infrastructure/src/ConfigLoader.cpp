#include "ConfigLoader.h"
#include <stdexcept>
#include <fstream>
#include <unordered_map>

// Function to load data from a config file that will return a Config object 
Config ConfigLoader::load(const std::string& filePath){
    // Opening the file whose path is provided 
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open config file " + filePath);
    }

    // Declaring unordered map to store the lines read from the file in a key-value pair 
    std::unordered_map<std::string, std::string> values;
    std::string line;
    
    while (std::getline(file, line))
    {
        size_t equalPos = line.find("=");
        if (equalPos == std::string::npos)
        {
            continue; //Ignoring the wrong formatted line
        }

        // Separating key and values from the line 
        std::string key = line.substr(0, equalPos);
        std::string value = line.substr(equalPos + 1);

        // Filling the separated key and value pairs in the unordered map 
        values[key] = value;
    }

    // Finding the values of the known keys from the unordered map and storing them in variables that will be passed to the Config constructor later 
    unsigned short port = static_cast<unsigned short>(std::stoi(values.at("port")));
    std::string bindAddress = values.at("bindAddress");

    // Passing the created variables containing the values from the unordered map to the Config' constructor and returning it 
    return Config(port, bindAddress);
}