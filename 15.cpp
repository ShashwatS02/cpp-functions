#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long initial_val = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                initial_val += a[i];
            } else {
                initial_val -= a[i];
            }
        }
        
        long long result = initial_val;
        
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                vector<long long> temp = a;
                reverse(temp.begin() + l, temp.begin() + r + 1);
                
                long long val_after_swap = 0;
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0) {
                        val_after_swap += temp[i];
                    } else {
                        val_after_swap -= temp[i];
                    }
                }
                
                long long swap_cost = r - l;
                long long total = swap_cost + val_after_swap;
                
                result = max(result, total);
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}