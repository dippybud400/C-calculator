#include "FileOutput.cpp"
#include "TerminalOutput.cpp"
#include <vector>
#include <sstream>

struct Result{
    int a;
    std::string operand;
    int b;
    int result;
    
};

class History : public FileOutput, public TerminalOutput{
    private:
        std::vector<Result> results;
    public:
        void addRegistry(int a, std::string op, int b, int result){
            results.push_back({a, op, b, result});
        }
        
        void show(){
            for(const auto& r : results){
                std::cout << r.a << " " << r.operand << " " << r.b << " = " << r.result << "\n";
            }
        }
        
        std::string toString(){
            std::stringstream ss;
            for(const auto& r : results){
                ss << r.a << " " << r.operand << " " << r.b << " = " << r.result << "\n";
            }
            return ss.str();
        }    
        
        void writeToFile(const std::string& fileName, const std::string& content) override {
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