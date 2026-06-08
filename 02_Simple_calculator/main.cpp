#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "=============================\n";
    cout << "      SIMPLE CALCULATOR      \n";
    cout << "=============================\n";

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> num2;

    switch (operation) {
        case '+':
            cout << "\nResult = " << num1 + num2;
            break;

        case '-':
            cout << "\nResult = " << num1 - num2;
            break;

        case '*':
            cout << "\nResult = " << num1 * num2;
            break;

        case '/':
            if (num2 != 0)
                cout << "\nResult = " << num1 / num2;
            else
                cout << "\nError! Division by zero is not allowed.";
            break;

        default:
            cout << "\nInvalid operator!";
    }

    cout << "\n\nThank you for using the calculator.\n";

    return 0;
}