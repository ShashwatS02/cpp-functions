#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void solve_test() {
    int n;
    long long k, l, r;
    std::cin >> n >> k >> l >> r;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long valid_segment_count = 0;
    int k_finder_ptr = 0;
    int k1_finder_ptr = 0;
    std::map<int, int> k_freq_map;
    std::map<int, int> k1_freq_map;

    for (int left_ptr = 0; left_ptr < n; ++left_ptr) {
        while (k_finder_ptr < n && k_freq_map.size() < k) {
            k_freq_map[a[k_finder_ptr]]++;
            k_finder_ptr++;
        }

        while (k1_finder_ptr < n && k1_freq_map.size() <= k) {
            k1_freq_map[a[k1_finder_ptr]]++;
            k1_finder_ptr++;
        }

        if (k_freq_map.size() < k) {
            break; 
        }

        long long end_min_distinct = k_finder_ptr - 1;
        long long end_max_distinct = (k1_freq_map.size() > k) ? (k1_finder_ptr - 2) : (n - 1);
        
        long long end_min_len = left_ptr + l - 1;
        long long end_max_len = left_ptr + r - 1;

        long long final_end_start = std::max(end_min_distinct, end_min_len);
        long long final_end_stop = std::min(end_max_distinct, end_max_len);

        if (final_end_start <= final_end_stop) {
            valid_segment_count += (final_end_stop - final_end_start + 1);
        }

        k_freq_map[a[left_ptr]]--;
        if (k_freq_map[a[left_ptr]] == 0) {
            k_freq_map.erase(a[left_ptr]);
        }
        k1_freq_map[a[left_ptr]]--;
        if (k1_freq_map[a[left_ptr]] == 0) {
            k1_freq_map.erase(a[left_ptr]);
        }
    }
    std::cout << valid_segment_count << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve_test();
    }
    return 0;
}