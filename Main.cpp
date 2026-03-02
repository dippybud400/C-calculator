#include <iostream>
#include "calculator/Modulus.cpp"
#include "calculator/SecureDivision.cpp"
#include "history/History.cpp"

using namespace std;

int main(){
	int a = 5;
	int b = 2;
	History h;
	SecureDivision d;
	Modulus m;
	int result = m.calculate(a, b);
	h.addRegistry("%", a, b, result);
	result = d.calculate(a, b);
	h.addRegistry("/", a, b, result);
	h.show();
	return 0;
}
