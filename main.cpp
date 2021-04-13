#include <iostream>
#include <cmath>


using namespace std;

void displayInitialMessage() {
    cout << "Welcome!" << endl;
    cout << "To begin please enter a value positive value of n" << endl;
}

void displaySecondMessage() {
    cout << "Please enter a number and then the operation you want to apply," << endl;
    cout << "followed by the second number." << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Input: ";
}

int getGCD(int second, int n, int *a, int *b) {

    if (second == 0) {
        *a = 0, *b = 1;
        return n;
    }

    //used to store the results of the recursion
    int x, y;
    int gcd = getGCD(n%second, second, &x, &y);

    //updating the values
    *a = y - (n/second) * x;
    *b = x;

    return gcd;
}

int calcInverse(int second, int n) {
    //needed for the GCD algorithm
    int a, b;
    int gcd = getGCD(second, n, &a, &b);

    if (gcd != 1) {
        return  -1;
    }

    return (a%n + n) % n;

}

void doDivision(int first, int second, int n) {
    first = first % n;

    int inverse = calcInverse(second, n);

    if (inverse == -1) {
        cout << "Division not possible" << endl;
    } else {
        cout << "Result: " << (inverse * first) % n << endl;
    }
}

void doComputation(int first, int second, char operation, int n) {
    int result;
    char decision;
    do {
        switch(operation){
            case '+':
                result = (first + second) % n;
                cout << "Result: " << result << endl;
                break;
            case '-':
                result = (first - second) % n;
                cout << "Result: " << abs(result) << endl;
                break;
            case '/':
                if (second == 0) {
                    cout << "Division by 0 not allowed" << endl;
                } else {
                    doDivision(first, second, n);
                }
                break;
            case '*':
                result = (first * second) % n;
                cout << "Result: " << result << endl;
                break;
            case '^':
                result = (int)pow(first, second) % n;
                cout << "Result: " << result << endl;
                break;
            default:
                cout << "Not a valid operation. Try again.";
                break;
        }

        cout << "Do another operation? y - yes | n - no" << endl;
        cin >> decision;

        if (decision == 'y') {
            cout << "Enter the first number, operation, the second number and n" << endl;
            cin >> first >> operation >> second >> n;
        } else {
            break;
        }
    } while (true);
}


int main() {

    //declaring variables
    char operation;
    int firstNum, secondNum, n;

    do {
        displayInitialMessage();
        cin >> n;
    } while (n <= 0);

    displaySecondMessage();

    cin >> firstNum >> operation >> secondNum;

    doComputation(firstNum, secondNum, operation, n);

    return 0;
}
