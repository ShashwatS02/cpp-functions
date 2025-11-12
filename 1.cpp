#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m, a;
    if (!(cin >> n >> m >> a)) return 0;
    long long x = (n + a - 1) / a;  // ceil(n/a) for positive integers
    long long y = (m + a - 1) / a;  // ceil(m/a)
    cout << x * y << '\n';
}
