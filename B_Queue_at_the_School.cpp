#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    for (; t--; ) {
        for (int j = n - 1; j > 0; --j) {
            if (s[j] == 'G' && s[j - 1] == 'B') {
                swap(s[j], s[j - 1]);
                --j;
            }
        }
    }
    cout << s << '\n';
}
