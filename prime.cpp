#include <iostream>
using namespace std;

bool prime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
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
        if (prime(i) == true)
        {
            cout << i << " ";
        }
    }

    return 0;
}