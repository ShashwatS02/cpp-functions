#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows for the pattern (half-height): ";
    cin >> n;

    // Upper part of the diamond
    for (int i = 1; i <= n; i++)
    {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        // Print alphabets
        char ch = 'A';
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }

    // Lower part of the diamond
    for (int i = n - 1; i >= 1; i--)
    {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        // Print alphabets
        char ch = 'A';
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }

    return 0;
}
