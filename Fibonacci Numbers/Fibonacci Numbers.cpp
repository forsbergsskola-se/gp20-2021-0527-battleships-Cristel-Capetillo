#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

int getRecursiveFibonacci(int n) {
    if (n <= 1) return n;
    return getRecursiveFibonacci(n - 1) + getRecursiveFibonacci(n - 2);
}

int getIterativeFibonacci(int n) {
    int a = 0, b = 1, c, i;

    if (n == 0) return a;

    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int rememberFibonacci(int n) {

    std::vector<int> vectorForFibonacci(n + 2);
    int i;

    vectorForFibonacci[0] = 0;
    vectorForFibonacci[1] = 1;

    for (i = 2; i <= n; i++) {
        vectorForFibonacci[i] = vectorForFibonacci[i - 1] + vectorForFibonacci[i - 2];
    }
    return vectorForFibonacci[n];
}


int main() {
    int n;
    cout << "Welcome to the Fibonacci finder! The app is ready to use. " << endl;
    cout << "Type your desired Fibonacci number: " << endl;
    cin >> n;
    auto start = high_resolution_clock::now();
    auto fibonacciNumber = getRecursiveFibonacci(n);

    auto stop = high_resolution_clock::now();
    milliseconds getDurationOne = duration_cast<milliseconds>(stop - start);
    cout << "Found the number " << fibonacciNumber << " in " << getDurationOne.count() << " milliseconds by the recursive method." << endl;

    fibonacciNumber = 0;

    start = high_resolution_clock::now();
    fibonacciNumber = rememberFibonacci(n);
    stop = high_resolution_clock::now();
    nanoseconds getDurationTwo = duration_cast<nanoseconds>(stop - start);
    cout << "Found the number " << fibonacciNumber << " in " << getDurationTwo.count() << " nanoseconds by looking at the array storage." << endl;

    fibonacciNumber = 0;

    start = high_resolution_clock::now();
    fibonacciNumber = getIterativeFibonacci(n);
    stop = high_resolution_clock::now();
    getDurationTwo = duration_cast<nanoseconds>(stop - start);
    cout << "Found the number " << fibonacciNumber << " in " << getDurationTwo.count() << " nanoseconds by the iterative method." << endl;

    getchar();

    return 0;
}