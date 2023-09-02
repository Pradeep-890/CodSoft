 //Simple Calculator 
#include <iostream>
using namespace std;

int main() {
    cout << "WELCOME TO MY CALCULATOR" << endl;
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Operation you want to perform (+, -, *, /): ";
    char operation; // Use char for the operation

    cin >> operation; // Read the operation character

    switch (operation) { // Use operation variable in the switch
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << static_cast<double>(num1) / num2 << endl;
            } else {
                cout << "Error: Division by zero" << endl;
            }
            break;
        default:
            cout << "Incorrect Operation" << endl;
            break;
    }

    return 0;
}
