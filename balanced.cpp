// balanced.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

class balanced {

private:

    void inputFile();
    char stack();

public:

    void driver();

};


void balanced::driver() {

    inputFile();
    stack();

}

// Methods 


// Input file checker

void balanced::inputFile() {

    cout << "Welcome to the program" << endl;

    cout << endl;

    ifstream inputFile;

    inputFile.open("inputString.txt");

    if (!inputFile.is_open()) {
        cout << "Try again, file not found." << endl;

        exit(0);

    }
    
    cout << "File has been found." << endl;

    cout << endl;

}

// Stsck 

char balanced::stack() {

    // variables

    std::stack<char> myStack;

    char tempChar;

    int rightpre = 0, leftpre = 0;
    
    ifstream inputFile;

    inputFile.open("inputString.txt");

    // While inputFile is NOT at the EOF push Char into the stack. 

    while (!inputFile.eof()) {
          
        while (inputFile.get(tempChar)) {
            
            cout << tempChar;  
            myStack.push(tempChar);

        }    
    }

    cout << endl;

    // While the stack is NOT empty transverse through and count the number of parentheses. Pop after each iteration.

    while (!myStack.empty()) {

        if (myStack.top() == '(') {
            ++leftpre;
        }

        else if (myStack.top() == ')') {
            ++rightpre;
        }

        cout << myStack.top();
        myStack.pop();

    };

    cout << endl;
    cout << endl;

    // Parentheses count

    cout << "Left parentheses: " << leftpre << endl;

    cout << "Right parentheses: "<< rightpre << endl;

    cout << endl;

    // Compare parentheses results 

    if (leftpre != rightpre) {

        cout << "Values are not equal" << endl;

    }

    else
        cout << "Values are equal." << endl;

    inputFile.close();

    return 0;
             
}

int main()
{

    balanced run;

    run.driver();

    system("pause");

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
