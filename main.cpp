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

void doComputation(int first, int second, char operation) {
    do {
        switch(operation){
            case '+':
                first += second;
                break;
            case '-':
                first -= second;
                break;
            case '/':
                if (second == 0) {
                    cout << "Division by 0 not allowed" << endl;
                } else if ( first % second != 0) {
                    cout << "Division not possible" << endl;
                } else {
                    first /= second;
                }
                break;
            case '*':
                first *= second;
                break;
            case '^':
                first = pow(first, second);
                break;
            default:
                cout << "Not a valid operation. Try again.";
                break;
        }
        cout << "Result: " << first << endl;
        cout << "Enter operation and number" << endl;
        cin >> operation;
        if (operation == 'q') {
            break;
        } else {
            cin >> second;
        }
    } while (true);
}


int main() {

    //declaring variables
    char operation;
    int firstNum, secondNum;

    displayInitialMessage();

    cin >> firstNum >> operation >> secondNum;

    doComputation(firstNum, secondNum, operation);

    return 0;
}
