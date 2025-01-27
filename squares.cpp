#include <iostream>
using namespace std;

int squares(int num)
{
    int sq = num * num;
    return sq;
}

int main()
{

    for (int i = 1; i <= 5; i++)
    {
        cout << squares(i) << " ";
    }

    return 0;
}