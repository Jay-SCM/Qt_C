#include <iostream>
#include <cmath>
using namespace std;

// Function to perform basic operations (+, -, *, /)
double performOperation(double num1, double num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
        default:
            cout << "Error: Invalid operator!" << endl;
            return 0;
    }
}

// Function to perform scientific operations (e.g., sqrt, sin, cos, tan, log, exp)
double performScientificOperation(double num, char op) {
    switch (op) {
        case 's':
            return sin(num);
        case 'c':
            return cos(num);
        case 't':
            return tan(num);
        case 'l':
            return log10(num);
        case 'e':
            return exp(num);
        default:
            cout << "Error: Invalid operator!" << endl;
            return 0;
    }
}

int main() {
    double result = 0;
    char op = '+';

    cout << "Simple Scientific Calculator" << endl;
    cout << "Enter an expression or type 'exit' to quit." << endl;

    while (true) {
        string input;
        cout << ">> ";
        cin >> input;

        if (input == "exit") {
            break;
        }

        double number;
        char operation;

        if (isdigit(input[0])) {
            // Input is a number
            cin.putback(input[0]);
            cin >> number;
            result = performOperation(result, number, op);
        } else {
            // Input is an operator or scientific function
            if (input.size() == 1) {
                op = input[0];
            } else if (input.size() == 3) {
                operation = input[0];
                cin >> number;
                result = performScientificOperation(number, operation);
            }
        }

        cout << "Result: " << result << endl;
    }

    return 0;
}

