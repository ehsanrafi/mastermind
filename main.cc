#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string SECRET_CODE;

bool IS_VALID(int i) {
    if (i >= 12345 and i <= 98765) {
        int numArray[5];
        int ax = i;
        for (int j = 0; j < 5; j++) {
            if (ax % 10 == 0) {
                return false;
            }
            numArray[j] = ax % 10; //Add 4 - j
            ax = ax / 10;
        }
        int k = 0;
        while (k < 5) {
            int l = 0;
            while (l < 5) {
                if (k != l and numArray[k] == numArray[l]) {
                    return false;
                }
                l++;
            }
            k++;
        } 
    }
    else {
        return false;
    }

    return true;
}

string GAME_SCORE(string GUESS) {
    string score = string(5, '-');
    for (int i = 0; i < GUESS.length(); i++) {
        for (int j = 0; j < SECRET_CODE.length(); j++) {
            if (GUESS[i] == SECRET_CODE[j]) {
                if (i == j) {
                    score[i] = 'X'; 
                }
                else {
                    score[i] = 'O';
                }
                break;
            }
        }
    }

    return score;
}

int main() {
    srand(time(0));
    cout << "******* Welcome to Mastermind v.01 *******" << endl;
    cout << "Which mode do you wanna play? Manual [M] or Automatic [A]: ";

    bool f = false;
    char m;
    
    cin >> m;
    if (m == 'M') {
        while (true) {
            cin >> SECRET_CODE;

            bool numeric = true;

            for (char c : SECRET_CODE) {
                if (!isdigit(c)) {
                    numeric = false;
                    break;
                }
            }

            if (!numeric or !IS_VALID(stoi(SECRET_CODE))) {
                cout << "Incorrect code. Try again." << endl;
            }
            else {
                cout << "Code introduced correctly. " << endl;
                break;
            }
        }
    }
    else if (m == 'A') {
        int auxCode = 0;

        while (true) {
            auxCode = rand() % 86419 + 12345;
            if (IS_VALID(auxCode)) {
                break;
            }
        }

        SECRET_CODE = to_string(auxCode);
        cout << "Code generated succesfully!" << endl;
    }
    else {
        cout << "Wrong input! Try again: " << endl;
    }

    bool END_GAME = false;
    int COUNTER = 0;
    string GUESS;

    cout << "Game started. Make your guess: " << endl;
    while (!END_GAME and COUNTER < 10) {
        cin >> GUESS;
        bool numeric = true;

        for (char c : GUESS) {
            if (!isdigit(c)) {
                numeric = false;
                break;
            }
        }

        if (!numeric) {
            cout << "Incorrect input. Try again. " << endl;
        }
        else {
            if (!IS_VALID(stoi(GUESS))) {
                cout << "Incorrect code. Try again. " << endl;
            }
            else {
                cout << "Your guess: " << GUESS << endl;

                string SCORE = GAME_SCORE(GUESS);

                cout << "Score " << SCORE << endl;
                
                COUNTER++;

                if (SCORE == "XXXXX") {
                    END_GAME = true;
                    cout << "You won!" << endl;
                }
                else if (COUNTER == 10) {
                    cout << "You have no attempts left. The code was: " << SECRET_CODE << endl;
                }
            }
        }
    }
}