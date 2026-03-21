#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const long long INF = 4e18; 

void solve_and_print() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    
    vector<vector<long long>> dp(n + 1, vector<long long>(2, INF));

    
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        
        long long prev_cost_for_zero = min(dp[i - 1][0], dp[i - 1][1]);
        if (prev_cost_for_zero != INF) {
            dp[i][0] = prev_cost_for_zero + a[i - 1];
        }

        
        if (i >= 2) {
            long long prev_cost_for_pair = dp[i - 2][0];
            if (prev_cost_for_pair != INF) {
                dp[i][1] = prev_cost_for_pair + abs(a[i - 2] - a[i - 1]);
            }
        }
    }

    cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case_count;
    cin >> test_case_count;
    while (test_case_count--) {
        solve_and_print();
    }

    return 0;
}