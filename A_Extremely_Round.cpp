#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int d = (int)s.size();
        int first = s[0] - '0';
        int ans = 9 * (d - 1) + first;
        cout << ans << '\n';
    }
    return 0;
}
