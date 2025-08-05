#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int result = 0;

    while (n > 0)
    {
        int remainder;
        remainder = n % 10;
        result = result * 10 + remainder;
        n /= 10;
    }
    cout << result;

    return 0;
}