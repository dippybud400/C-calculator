#include <iostream>
#include "calculator/Modulus.cpp"
#include "history/History.cpp"

using namespace std;

int main(){
	int a = 5;
	int b = 2;
	History h;
	Modulus m;
	int result = m.calculate(a, b);
	h.addRegistry("%", a, b, result);
	h.show();
	return 0;
}
