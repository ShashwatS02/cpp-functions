#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vint vector<ll>
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vint arr(n);
    for (ll &x : arr) cin >> x;
    ll correct = 0;
    for (ll idx = 0; idx < n; ++idx)
        if (arr[idx] == idx + 1) ++correct;
    cout << (correct + 1) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases; cin >> cases;
    while (cases--) solve();
    return 0;
}
