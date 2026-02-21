#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int N = 2 * n;
        vector<int> pos[n+1];
        for (int i = 1; i <= N; ++i) {
            cout << "? " << 1 << " " << i << endl;
            cout.flush();
            int v; cin >> v;
            pos[v].push_back(i);
        }
        vector<int> a(N + 1, 0);
        for (int num = 1; num <= n; ++num) {
            for (int idx : pos[num]) a[idx] = num;
        }
        cout << "!";
        for (int i = 1; i <= N; ++i) cout << " " << a[i];
        cout << endl;
        cout.flush();
    }
    return 0;
}
