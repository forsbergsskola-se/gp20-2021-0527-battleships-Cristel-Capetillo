#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    cout << "Type your desired number of iterations: " << endl;
    float iterations;
    cin >> iterations;

    float randomPool[20] = {};
    int randomNumber;

    srand(time(0));

    for (int i = 0; i <= iterations; i++) {
        randomNumber = rand() % 20 + 1;
        randomPool[randomNumber - 1] += 1;
    }

    cout << endl;

    for (int i = 0; i < 20;i++) {
        float selectRandom = (randomPool[i] / iterations) * 100;
        cout << "Number: " <<  i + 1  << " might appear: " << randomPool[i] << " times " << " with a probability of (" << selectRandom << " % )" << endl;
    }
}

