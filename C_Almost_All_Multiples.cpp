#include <bits/stdc++.h>
using namespace std;

static void solve() {
    int n, x;
    cin >> n >> x;

    if (n % x != 0) {
        cout << -1 << "\n";
        return;
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) p[i] = i;

    p[1] = x;
    p[n] = 1;

    int cur = x;
    while (cur != n) {
        int nxt = -1;
        for (int m = cur * 2; m <= n; m += cur) {
            if (n % m == 0) { nxt = m; break; }
        }
        if (nxt == -1) {
            cout << -1 << "\n";
            return;
        }
        p[cur] = nxt;
        cur = nxt;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << p[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
