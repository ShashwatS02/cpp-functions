#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, n; cin >> a >> b >> n;
    vector<int> v(n); 
    for (auto& x : v) cin >> x;
    sort(v.begin(), v.end());

    long long res = b;
    int limit = a - 1;
    for (int x : v) res += min(x, limit);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
