#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> array(num);
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < num; i++) {
        cin >> array[i];
        if (array[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    if (evenCount == 1) {
        for (int i = 0; i < num; i++) {
            if (array[i] % 2 == 0)
                cout << i + 1 << endl;
        }
    } else if (oddCount == 1) {
        for (int i = 0; i < num; i++) {
            if (array[i] % 2 == 1)
                cout << i + 1 << endl;
        }
    }
}
