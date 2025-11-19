#include <iostream>
using namespace std;

int main() {
    int t, res = 0;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        res += (b - a > 1);
    }
    cout << res << '\n';
}
