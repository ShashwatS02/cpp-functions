#include <iostream>
using namespace std;

int main() {
    int m; cin >> m;
    cout << "I hate";
    for (int j = 1; j < m; j++)
        cout << (j % 2 ? " that I love" : " that I hate");
    cout << " it";
    return 0;
}
