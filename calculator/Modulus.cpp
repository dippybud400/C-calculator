#include "Operator.cpp"

class Modulus : public Operator{
    public:
        int calculate(int a, int b){
            return a % b;
        }    
};