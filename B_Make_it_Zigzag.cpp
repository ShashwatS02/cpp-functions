#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;


const long long INF = 1e18 + 7;


long long get_base(int index, int mode, const vector<long long>& arr, const vector<long long>& prefix_max) {
    if (mode == 0) {
        return arr[index];
    }
    return prefix_max[index];
}

void solve_problem() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> pmax(n);
    long long current_prefix_max = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        current_prefix_max = max(current_prefix_max, a[i]);
        pmax[i] = current_prefix_max;
    }

    if (n <= 1) {
        cout << 0 << "\n";
        return;
    }

    
    vector<vector<long long>> dp(n, vector<long long>(2, INF));

    
    for (int m1 = 0; m1 <= 1; ++m1) {
        long long b1_base = get_base(1, m1, a, pmax);
        if (b1_base < 2) {
            
            continue;
        }

        long long cost_for_valley0 = INF;
        for (int m0 = 0; m0 <= 1; ++m0) {
            long long b0_base = get_base(0, m0, a, pmax);
            
            long long target_b0 = max(1LL, min(b0_base, b1_base - 1));
            cost_for_valley0 = min(cost_for_valley0, b0_base - target_b0);
        }
        dp[1][m1] = cost_for_valley0;
    }

    
    for (int i = 3; i < n; i += 2) {
        for (int mi = 0; mi <= 1; ++mi) {
            long long bi_base = get_base(i, mi, a, pmax);
            if (bi_base < 2) {
                
                continue;
            }

            long long min_cost_to_reach_here = INF;
            for (int mi_minus_2 = 0; mi_minus_2 <= 1; ++mi_minus_2) {
                long long prev_peak_cost = dp[i - 2][mi_minus_2];
                if (prev_peak_cost == INF) {
                    continue;
                }
                
                long long bi_minus_2_base = get_base(i - 2, mi_minus_2, a, pmax);
                

                long long valley_cost = INF;
                for (int mi_minus_1 = 0; mi_minus_1 <= 1; ++mi_minus_1) {
                    long long bi_minus_1_base = get_base(i - 1, mi_minus_1, a, pmax);
                    
                    long long target_b_valley = max(1LL, min({bi_minus_1_base, bi_minus_2_base - 1, bi_base - 1}));
                    valley_cost = min(valley_cost, bi_minus_1_base - target_b_valley);
                }
                min_cost_to_reach_here = min(min_cost_to_reach_here, prev_peak_cost + valley_cost);
            }
            dp[i][mi] = min_cost_to_reach_here;
        }
    }

    long long final_ans = INF;
    if (n % 2 == 0) {
        
        int last_peak_idx = n - 1;
        final_ans = min(dp[last_peak_idx][0], dp[last_peak_idx][1]);
    } else {
        
        int last_peak_idx = n - 2;
        for (int m_peak = 0; m_peak <= 1; ++m_peak) {
            long long cost_before_final = dp[last_peak_idx][m_peak];
            if (cost_before_final == INF) {
                continue;
            }
            
            long long b_peak_base = get_base(last_peak_idx, m_peak, a, pmax);
            
            long long final_valley_cost = INF;
            for (int m_valley = 0; m_valley <= 1; ++m_valley) {
                long long b_valley_base = get_base(n - 1, m_valley, a, pmax);
               
                long long target_b_final = max(1LL, min(b_valley_base, b_peak_base - 1));
                final_valley_cost = min(final_valley_cost, b_valley_base - target_b_final);
            }
            final_ans = min(final_ans, cost_before_final + final_valley_cost);
        }
    }

    cout << final_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve_problem();
    }
    return 0;
}