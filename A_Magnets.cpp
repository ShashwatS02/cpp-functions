#include <iostream>
using namespace std;

int main() {
    int n, prev = -1, res = 0, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x != prev) ++res;
        prev = x;
    }
    cout << res << '\n';
}
