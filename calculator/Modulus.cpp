
#include "Operand.cpp"

class Modulus : public Operand{
	public:
		int calculate(int a, int b){
			return a % b;
		}

};
