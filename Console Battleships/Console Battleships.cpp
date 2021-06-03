#include <string>
#include <iostream>
#include <process.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int const rowAmount = 10;
int const columnAmount = 10;
int shipX, shipY;
int totalGuesses = 5;
int grid[rowAmount][columnAmount];
bool isWinner = false;

void displayWinMessage() {
    cout << "You win with " << totalGuesses << " guesses left (:" << endl;
}


void createGrid() {

    for (int x = 0; x < rowAmount; x++) {
        for (int y = 0; y < columnAmount; y++) {
            grid[x][y] = 0;
            cout << "|" << x << "," << y << "|";
        }
        cout << endl;
    }
}


void setShipCoordinates() {
    shipX = 0 + (rand() % rowAmount);
    shipY = 0 + (rand() % columnAmount);
    grid[shipX][shipY] = 2;
}


void displayGrid(int changeX, int changeY) {
    cout << "_______________________________________" << endl;

    for (int x = 0; x < rowAmount; x++) {
        for (int y = 0; y < columnAmount; y++) {
            if (x == changeX && y == changeY) {
                if (grid[x][y] != 2) {
                    grid[x][y] = 1;
                }
            }

            if (grid[x][y] == 0) {
                cout << "|" << x << "," << y << "|";
            }
            else if (grid[x][y] == 1) {
                cout << "|X,X|";
            }

            if (grid[x][y] == 2) {
                if (x == changeX && y == changeY) {
                    cout << "|HIT|";
                }
                else {
                    cout << "|" << x << "," << y << "|";
                }
            }

        }
        cout << endl;
    }
}


void playerInput(){
    int guessX, guessY{};
    bool isCorrectGuess = false;

    cout << endl;
    do {
        cout << "You have " << totalGuesses << " guesses left." << endl;

        cout << "X says: ";
        cin >> guessX;
        if (guessX < 0 || guessX>2) {
            isCorrectGuess = false;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Miss!" << endl;
            break;
        }
        else {
            isCorrectGuess = true;
        }

        cout << "Y says: ";
        cin >> guessY;
        if (guessY < 0 || guessY>2) {
            isCorrectGuess = false;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Miss!" << endl;
            break;
        }
        else {
            isCorrectGuess = true;
        }

        displayGrid(guessX, guessY);
        cout << endl;
        totalGuesses--;


    } while (!isCorrectGuess);


    if (guessX == shipX && guessY == shipY) {
        isWinner = true;
        displayWinMessage();
    }
}




void main() {
    srand(time(NULL));
    cout << "Welcome to Lil Console Battleship! Game is ready." << endl << endl;
    int grid[rowAmount][columnAmount];

    createGrid();
    setShipCoordinates();

    do {
        if (isWinner) {
            break;
        }

        playerInput();
    } while (totalGuesses > 0);

    if (!isWinner)
        cout << "You lose :(" << endl;

    cout << "The ship was located at |" << shipX << "," << shipY << "|." << endl;
}