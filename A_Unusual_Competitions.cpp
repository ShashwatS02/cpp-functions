#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    string s;
    if (!(cin >> n >> s)) return 0;
    if (n % 2 || (long long)s.size() != n) { cout << -1 << "\n"; return 0; }

    long long bal = 0, total = 0;
    long long ans = 0, start = 0;
    bool bad = false;

    for (long long i = 0; i < n; ++i) {
        long long v = (s[i] == '(' ? 1 : -1);
        total += v;
        bal += v;
        if (bal < 0) bad = true;
        if (bal == 0) {
            if (bad) ans += (i - start + 1);
            start = i + 1;
            bad = false;
        }
    }

    if (total != 0) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}
