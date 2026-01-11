#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


const long long INF = 4e18;


long long cost_for_three(long long v1, long long v2, long long v3) {
    long long mx = v1;
    if (v2 > mx) mx = v2;
    if (v3 > mx) mx = v3;

    long long mn = v1;
    if (v2 < mn) mn = v2;
    if (v3 < mn) mn = v3;
    
    return mx - mn;
}


long long solve_linear_subarray(const vector<long long>& arr, int start_idx, int len) {
    if (len == 0) {
        return 0;
    }

    vector<long long> dp(len + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= len; ++i) {
        
        if (i >= 2 && dp[i-2] < INF) {
            long long cost2 = abs(arr[start_idx + i - 1] - arr[start_idx + i - 2]);
            dp[i] = min(dp[i], dp[i-2] + cost2);
        }
        
        if (i >= 3 && dp[i-3] < INF) {
            long long cost3 = cost_for_three(arr[start_idx + i - 3], arr[start_idx + i - 2], arr[start_idx + i - 1]);
            dp[i] = min(dp[i], dp[i-3] + cost3);
        }
    }
    return dp[len];
}

void process_case() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    
    long long min_ops = solve_linear_subarray(a, 0, n);

    
    if (n >= 2) {
        long long res = solve_linear_subarray(a, 1, n - 2);
        if (res < INF) {
            min_ops = min(min_ops, abs(a[n - 1] - a[0]) + res);
        }
    }

    
    if (n >= 3) {
        long long res = solve_linear_subarray(a, 1, n - 3);
        if (res < INF) {
            min_ops = min(min_ops, cost_for_three(a[n - 2], a[n - 1], a[0]) + res);
        }
    }
    
    
    if (n >= 3) {
        long long res = solve_linear_subarray(a, 2, n - 3);
        if (res < INF) {
             min_ops = min(min_ops, cost_for_three(a[n - 1], a[0], a[1]) + res);
        }
    }
    
    cout << min_ops << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        process_case();
    }

    return 0;
}