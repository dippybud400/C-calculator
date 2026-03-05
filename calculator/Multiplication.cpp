#include "Operator.cpp"
class Multiplication : public Operator{
    public:
       int calculate(int a, int b){
                return a * b;
           }    
};