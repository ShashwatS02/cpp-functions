#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; i64 X; 
        cin >> n >> X;
        vector<i64> a(n);
        i64 S = 0;
        for (auto &v : a) cin >> v, S += v;
        sort(a.begin(), a.end());
        i64 K = S / X;
        int m = n - (int)K;
        vector<i64> small(a.begin(), a.begin() + m), big(a.begin() + m, a.end());
        i64 bonus = 0;
        for (auto v : big) bonus += v;
        vector<i64> out; out.reserve(n);
        i64 need = X;
        int i = 0, j = 0;
        while ((int)out.size() < n) {
            if (i < (int)small.size() && small[i] < need) {
                need -= small[i];
                out.push_back(small[i++]);
            } else {
                i64 v = big[j++];
                out.push_back(v);
                i64 r = v - need;
                need = X - r;
                if (need == 0) need = X;
            }
        }
        cout << bonus << "\n";
        for (int t = 0; t < n; ++t) cout << (t ? " " : "") << out[t];
        cout << "\n";
    }
    return 0;
}
