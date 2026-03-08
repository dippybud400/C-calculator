#pragma once
#include <iostream> // necesary for performing file I/O
#include <fstream> // library for reading & writing files
#include <string>

class FileOutput{
      public:
      
      virtual void writeToFile(const std::string& fileName, const std::string& content) = 0;
    
};