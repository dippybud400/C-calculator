#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileOutput{
      public:
      
      virtual void writeToFile(const std::string& fileName, const std::string& content) = 0;
    
};