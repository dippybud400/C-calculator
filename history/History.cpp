#include "FileOutput.cpp"
#include "TerminalOutput.cpp"
#include <vector> // library for linked list storage
#include <sstream> // libary for outputing contents into a string format

struct Result{ // struct for defining operation
    int a;
    char operand;
    int b;
    int result;
    
};

class History : public FileOutput, public TerminalOutput{
    private:
        std::vector<Result> results;
    public:
        void addRegistry(int a, char op, int b, int result){ // adds recently performed ecuation
            results.push_back({a, op, b, result});
        }
        
        void show(){ // shows all of the recent operations stored
            for(const auto& r : results){
                std::cout << r.a << " " << r.operand << " " << r.b << " = " << r.result << "\n";
            }
        }
        
        std::string toString(){ // method to transform contents of file into a string format
            std::stringstream ss;
            for(const auto& r : results){
                ss << r.a << " " << r.operand << " " << r.b << " = " << r.result << "\n";
            }
            return ss.str();
        }    
        
        void writeToFile(const std::string& fileName, const std::string& content) override { // method for writing contents into an external file
        std::ofstream outFile(fileName, std::ios::out);

        if (outFile.is_open()) {
            outFile << content;
            outFile.close();
            std::cout << "Data written to file: " << fileName << std::endl;
        } else {
            std::cerr << "Error opening file: " << fileName << std::endl;
        }
    }
    
};