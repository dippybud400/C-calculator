#include "Operator.cpp"

class Division : public Operator{
    public:
        int calculate(int a, int b){
            if(b == 0){
                return 0;
            }
            return a / b;
        }    
};