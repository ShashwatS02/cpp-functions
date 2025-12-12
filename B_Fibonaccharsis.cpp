#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int,int> fib_coeff(int n) {
    if (n == 0) return {1,0};
    if (n == 1) return {0,1};
    pair<int,int> a = {1,0}, b = {0,1}, c;
    for (int i = 2; i <= n; i++) {
        c = {a.first + b.first, a.second + b.second};
        a = b; b = c;
    }
    return b;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k == 2) {
            cout << (n >= 0 && n <= n ? 1 : 0) << "\n";
            continue;
        }
        pair<int,int> coef = fib_coeff(k-3);
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            int left = n - coef.first * i;
            if (left % coef.second == 0) {
                int j = left / coef.second;
                if (j >= i && j <= n) cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
