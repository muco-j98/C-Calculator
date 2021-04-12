#include <iostream>
#include <cmath>

using namespace std;

void displayInitialMessage() {
    cout << "Welcome!" << endl;
    cout << "Please enter a number and then the operation you want to apply," << endl;
    cout << "followed by the second number." << endl;
    cout << "To exit press q" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Input: ";
}

void doComputation(float first, float second, char operation) {
    do {
        switch(operation){
            case '+':
                second += first;
                break;
            case '-':
                second -= first;
                break;
            case '/':
                if (second == 0) {
                    cout << "Division by 0 not allowed" << endl;
                } else {
                    second /= first;
                }
                break;
            case '*':
                second *= first;
                break;
            case '^':
                second = pow(first, second);
                break;
            default:
                cout << "Not a valid operation. Try again.";
                break;
        }

        cout << "Result: " << second << endl;

        cin >> operation;

        if (operation == 'q') break;

        else cin >> first;

    } while (true);
}


int main() {

    //declaring variables
    char operation;
    float firstNum, secondNum;

    displayInitialMessage();

    cin >> firstNum >> operation >> secondNum;

    doComputation(firstNum, secondNum, operation);

    return 0;
}
