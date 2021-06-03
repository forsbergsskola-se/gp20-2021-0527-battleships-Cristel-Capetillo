#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int getFibonacciRecursive(int n) {
    if (n <= 1) return n;
    return getFibonacciRecursive(n - 1) + getFibonacciRecursive(n - 2);
}

int getFibonacciIteration(int n) {
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
    std::vector<int> fibonacciVector(n + 2);
    int i;
    fibonacciVector[0] = 0;
    fibonacciVector[1] = 1;

    for (i = 2; i <= n; i++) {
        fibonacciVector[i] = fibonacciVector[i - 1] + fibonacciVector[i - 2];
    }

    return fibonacciVector[n];
}

int main() {
    int n;
    cout << "Type your desired number: " << endl;
    cin >> n;

    auto start = high_resolution_clock::now();
    auto fibonacciNumber = getFibonacciRecursive(n);
    auto stop = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(stop - start);
    cout << "Found the number " << fibonacciNumber << " in " << duration.count() << " milliseconds by the recursive method." << endl;

    fibonacciNumber = 0;

    start = high_resolution_clock::now();
    fibonacciNumber = rememberFibonacci(n);
    stop = high_resolution_clock::now();
    nanoseconds durationOne = duration_cast<nanoseconds>(stop - start);
    cout << "Found the number " << fibonacciNumber << " in " << duration.count() << " nanoseconds by checking the storage of old numbers." << endl;

    fibonacciNumber = 0;

    start = high_resolution_clock::now();
    fibonacciNumber = getFibonacciIteration(n);
    stop = high_resolution_clock::now();
    nanoseconds durationTwo = duration_cast<nanoseconds>(stop - start);
    cout << "Found the number " << fibonacciNumber << " in " << duration.count() << " nanoseconds by the iterative method." << endl;

    getchar();

    return 0;
}