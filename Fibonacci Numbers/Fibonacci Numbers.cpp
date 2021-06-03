// Fibonacci Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int getFibonacciRecursively(int n) {
    if (n < 2) return n;
    return getFibonacciRecursively(n - 1) + getFibonacciRecursively(n - 2);
}

int getFibonacciIteratively(int n) {
    int a = 1, b = 1, c = 0;

    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    while (true) {
        cout << "Type a number: " << endl;
        int i;
        cin >> i;

        //cout << "The number you typed by recursive method is: " << endl;
        getFibonacciRecursively;

        //cout << "The number you typed by iterative method is: " << endl;
        getFibonacciIteratively;
    }
}

