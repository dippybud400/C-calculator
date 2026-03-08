#include <iostream>
#include <string>
#include "calculator/Adition.cpp"
#include "calculator/Substraction.cpp"
#include "calculator/Multiplication.cpp"
#include "calculator/Division.cpp"
#include "calculator/Power.cpp"
#include "calculator/Modulus.cpp"
#include "history/History.cpp"

using namespace std;

bool fileWrite;
bool running;
const string saveFile = "results.txt";
const string version = "1.0.0"; // program version

Adition a;
Substraction s;
Multiplication m;
Power p;
Division d;
Modulus mod;
History h;

void setFileWrite(){ // initial function to choose if user wants file output
    char option;
    cout << "enable save to file?\n (y)es, (n)o\n";
    cin >> option;
    if(option == 'y'){
        fileWrite = true;
    }
    else if(option == 'n'){
        fileWrite = false;
    }
    else{
        cout<<"invalid option\n";
    }
}
void operate(string expr){
    int result;
    int num1 = expr[0] - '0'; // parsing from char to int (considering strings are just char chains)
    char op = expr[1];
    int num2 = expr[2] - '0';
    
    switch(op){
        case '+':
            result = a.calculate(num1, num2);
            h.addRegistry(num1, op, num2, result);
            cout<<result<<"\n";
            break;
        case '-':
            result = s.calculate(num1, num2);
            h.addRegistry(num1, op, num2, result);
            cout<<result<<"\n";
            break;
        case '/' :
            result = d.calculate(num1, num2);
            h.addRegistry(num1, op, num2, result);
            cout<<result<<"\n";
            break;
        case '*':
            result = m.calculate(num1, num2);
            h.addRegistry(num1, op, num2, result);
            cout<<result<<"\n";
            break;
        case '%' :
            result = mod.calculate(num1, num2);
            h.addRegistry(num1, op, num2, result);
            cout<<result<<"\n";
            break;
        case '^':
            result = p.calculate(num1, num2);
            h.addRegistry(num1, op, num2, result);
            cout<<result<<"\n";
            break;                 
        
        }
    if(fileWrite){
        h.writeToFile(saveFile, h.toString());
    }        
}
void menu(){
    running = true;
    while(running){
        int option = 0;
        string expr;
        cout <<"welcome to this CLI calculator <version " << version << ">" << "\n";
        cout <<"please choose an option"<<"\n";
        cout << "1: perform a calculation\n 2: show history\n 3: exit\n";
        cin >> option;
        switch(option){
            case 1:
                cout << "enter an expression ex:(2+5)\n";
                cin >> expr;
                operate(expr);
            break;
            case 2:
                h.show();
                break;
            case 3:
                running = false;
                break; 
            default:
                cout<<"invalid option"<<"\n";
                break;    
        }
    }                  
}




int main(){
	setFileWrite();
    menu();
    
	return 0;
}


    
   
