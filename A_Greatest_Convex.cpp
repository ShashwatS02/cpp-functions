#include <bits/stdc++.h>
using namespace std;

long long solve_one() {
    long long x;
    cin >> x;
    return x - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    if (!(cin >> tc)) return 0;
    while (tc--) {
        cout << solve_one() << '\n';
    }
    return 0;
}
