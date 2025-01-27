#include <iostream>
using namespace std;

int odd(int num)
{
    if (num % 2 != 0)
    {
        return num;
    }
    return 0;
}

int main()
{
    int num1, num2;
    cout << "Enter num1: ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;

    for (int i = num1; i <= num2; i++)
    {
        if (odd(i) == 0)
        {
            cout << "";
        }
        else
        {
            cout << odd(i) << " ";
        }
    }

    return 0;
}