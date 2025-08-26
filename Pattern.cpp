#include <iostream>
using namespace std;

int main() {

    int row, col;

    // for(row = 1; row <= 5; row++) {
    //     for (col = 1; col <= 5; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // for (row = 1; row <= 4; row++) {
    //     for (col = 1; col <= 5; col++){
    //         cout << 10 << " ";
    //     }
    //     cout << endl;
    // }

    // for(row = 1; row <= 5; row++) {
    //     for (col = 1; col <= 5; col++) {
    //         cout << row << " ";
    //     }
    //     cout << endl;
    // }

    // for(row = 1; row <= 5; row++) {
    //     for (col = 1; col <= 5; col++) {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }

    // for(row = 1; row <= 5; row++) {
    //     for (col = 5; col >= 1; col--) {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }

    // for(row = 1; row <= 5; row++) {
    //     for (col = 1; col <= 5; col++) {
    //         cout << col*col << " ";
    //     }
    //     cout << endl;
    // }

    // for(char r = 'a'; r <= 'e'; r++) {
    //     for (col = 1; col <= 5; col++) {
    //         cout << r << " ";
    //     }
    //     cout << endl;
    // }

    //OR

    // for(row = 1; row <= 5; row++) {
    //     char name = 'a' + (row - 1);
    //     for (col = 1; col <= 5; col++) {
    //         cout << name << " ";
    //     }
    //     cout << endl;
    // }

    // for (row = 1; row <= 5; row++) {
    //     for (char c = 'a'; c <= 'e'; c++) {
    //         cout << c << " ";
    //     }
    //     cout << endl;
    // }

    //OR

    // for (row = 1; row <= 5; row++) {
        
    //     for (col = 1; col <= 5; col++) {
    //         char name = 'a' + col - 1;
    //         cout << name << " ";
    //     }
    //     cout << endl;
    // }
    // int count = 1;
    // for (row = 1; row <= 5; row++) {
        
    //     for (col = 1; col <= 5; col++) {
            
    //         cout << count << " ";
    //         count++;
    //     }
    //     cout << endl;
    // }

    //OR

    for (row = 1; row <= 5; row++) {
        
        for (col = 1; col <= 5; col++) {
            
            cout << (row - 1)*5 + col << " ";
        }
        cout << endl;
    }

    return 0;
}