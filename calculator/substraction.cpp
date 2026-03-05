#include "Operator.cpp"
class Substraction : public Operator{
    public:
        int calculate(int a, int b){
                 return a - b;
        }
};