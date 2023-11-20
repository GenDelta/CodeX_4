#include <iostream>
#include <limits>

using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char currentPlayer = 'X';

// Function declarations
int checkWin();
void drawBoard();
void resetGame();

int main() {
    int choice;
    char playAgain;

    // Main game loop
    do {
        resetGame(); // Reset the game state for a new match

        // Match loop
        do {
            drawBoard(); // Draw the Tic Tac Toe board

            cout << "Player " << currentPlayer << ", enter a number (1-9): ";

            // Validate user input (check for non-numeric input and out-of-range values)
            while (!(cin >> choice) || choice < 1 || choice > 9) {
                cout << "Invalid input. Please enter a number between 1 and 9: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (square[choice] == '0' + choice) {
                square[choice] = currentPlayer;

                if (checkWin() == 1) {
                    drawBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break; // Exit the loop and end the current match
                } else if (checkWin() == 0) {
                    drawBoard();
                    cout << "It's a draw!" << endl;
                    break; // Exit the loop and end the current match
                }

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player for the next turn
            } else {
                cout << "Invalid move. Try again." << endl;
            }

        } while (checkWin() == -1);

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch starting player for the next match

        // Ask if the user wants to play again
        do {
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;

            if (playAgain == 'n' || playAgain == 'N') {
                cout << "Exiting the program. Thank you for playing!" << endl;
                return 0; // Exit the program
            } else if (playAgain == 'y' || playAgain == 'Y') {
                break; // Continue to the next match
            } else {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        } while (true);

    } while (true);

    return 0;
}

// Function to check for a win, loss, or draw
int checkWin() {
    // Check for a win
    for (int i = 1; i <= 7; i += 3) {
        if (square[i] == square[i + 1] && square[i + 1] == square[i + 2]) {
            return 1; // Win
        }
    }

    for (int i = 1; i <= 3; ++i) {
        if (square[i] == square[i + 3] && square[i + 3] == square[i + 6]) {
            return 1; // Win
        }
    }

    if ((square[1] == square[5] && square[5] == square[9]) ||
        (square[3] == square[5] && square[5] == square[7])) {
        return 1; // Win
    }

    // Check for a draw
    for (int i = 1; i <= 9; ++i) {
        if (square[i] == '0' + i) {
            return -1; // Game in progress
        }
    }

    return 0; // Draw
}

// Function to draw the Tic Tac Toe board
void drawBoard() {
    // Draw the Tic Tac Toe board with numbers
    cout << "Player 1 (" << currentPlayer << ")  -  Player 2 (" << ((currentPlayer == 'X') ? 'O' : 'X') << ")" << endl;
    cout << endl;

    for (int i = 1; i <= 9; i += 3) {
        cout << "     |     |     " << endl;
        cout << "  " << square[i] << "  |  " << square[i + 1] << "  |  " << square[i + 2] << endl;
        if (i != 7) {
            cout << "_____|_____|_____" << endl;
        }
    }

    cout << "     |     |     " << endl << endl;
}

// Function to reset the game state
void resetGame() {
    // Reset the game state
    for (int i = 1; i <= 9; ++i) {
        square[i] = '0' + i;
    }
}