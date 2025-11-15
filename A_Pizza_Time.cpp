#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        long long n; cin >> n;
        long long ans = 0;
        while (n > 2) {
            long long a = n / 3;   
            ans += a;
            n -= 2 * a;            
        }
        cout << ans << '\n';
    }
    return 0;
}
