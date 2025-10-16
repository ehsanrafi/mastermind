#include <iostream>
using namespace std;

int SECRET_CODE;

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

int main() {
    cout << "******* Welcome to Mastermind v.01 *******" << endl;
    cout << "Which mode do you wanna play? Manual [M] or Automatic [A]: ";

    bool f = false;
    char m;
    
    while (!f) {
        cin >> m;
        if (m == 'M') {
            while (true) {
                cin >> SECRET_CODE;
    
                if (!IS_VALID(SECRET_CODE)) {
                    cout << "Incorrect code. Try again." << endl;
                }
                else {
                    cout << "Code introduced correctly. " << endl;
                    break;
                }
            }
        }
        else if (m == 'A') {
            //automatic mode
        }
        else {
            cout << "Wrong input! Try again: " << endl;
        }
    }
}