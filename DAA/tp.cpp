#include <iostream>
using namespace std;

void guessingGame(int secretNumber) {
    int low = 1, high = 100; // Define the range of guessing
    int guess;
    int attempts = 0;

    cout << "Think of a number between " << low << " and " << high << ". I'll try to guess it!" << endl;

    while (low <= high) {
        attempts++;
        guess = (low + high) / 2; // Program guesses the midpoint

        cout << "Is your number " << guess << "? (Enter 'h' if higher, 'l' if lower, 'c' if correct): ";
        char response;
        cin >> response;

        if (response == 'c') {
            cout << "Yay! I guessed your number " << secretNumber << " in " << attempts << " attempts!" << endl;
            return;
        } else if (response == 'h') {
            low = guess + 1; // Adjust the range to higher
        } else if (response == 'l') {
            high = guess - 1; // Adjust the range to lower
        } else {
            cout << "Invalid input! Please enter 'h', 'l', or 'c'." << endl;
        }
    }

    cout << "Hmm, something went wrong. Are you sure your number is between " << low << " and " << high << "?" << endl;
}

int main() {
    int secretNumber;

    cout << "Enter the secret number for me to guess (between 1 and 100): ";
    cin >> secretNumber;

    // Validate the input
    if (secretNumber < 1 || secretNumber > 100) {
        cout << "Please enter a number between 1 and 100!" << endl;
        return 1;
    }

    guessingGame(secretNumber);

    return 0;
}
