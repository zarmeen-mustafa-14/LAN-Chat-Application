#include "ConsoleLogSink.h"
#include<iostream>
void ConsoleLogSink::write(const std::string&message){
    std::cout<<message<<std::endl;
}