#include <bits/stdc++.h>
using namespace std;

#define ll long long

inline ll comb3(ll x) {
    return (x < 3) ? 0 : (x * (x - 1) * (x - 2)) / 6;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    unordered_map<int, int> freq;
    for (auto &x : v) freq[x]++;

    ll ans = 0;
    for (auto &p : freq) ans += comb3(p.second);

    for (auto &x : v) {
        for (int d = 1; d * d <= x; ++d) {
            if (x % (d * d) == 0) {
                int f1 = x / d;
                int f2 = x / (d * d);
                if (freq.count(f1) && freq.count(f2)) ans += 1LL * freq[f1] * freq[f2];
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
