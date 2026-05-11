#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

const int MAX_VAL = 10000001;
vector<int> spf(MAX_VAL);

void sieve() {
    if (spf[2] == 2) return; // Sieve already run
    iota(spf.begin(), spf.end(), 0);
    for (long long i = 2; i * i < MAX_VAL; ++i) {
        if (spf[i] == i) { // i is prime
            for (long long j = i * i; j < MAX_VAL; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void get_divs(int n, vector<int>& divisors) {
    divisors.clear();
    if (n <= 0) return;
    
    map<int, int> prime_factors_map;
    int temp_n = n;
    while (temp_n != 1) {
        prime_factors_map[spf[temp_n]]++;
        temp_n /= spf[temp_n];
    }
    
    divisors.push_back(1);
    for (auto const& factor_pair : prime_factors_map) {
        int p = factor_pair.first;
        int exp = factor_pair.second;
        int current_size = divisors.size();
        int power_of_p = 1;
        for (int i = 0; i < exp; ++i) {
            power_of_p *= p;
            for (int j = 0; j < current_size; ++j) {
                divisors.push_back(divisors[j] * power_of_p);
            }
        }
    }
}

int gcd(int a, int b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

void solve() {
    int n;
    cin >> n;
    map<int, int> freq;
    set<int> unique_a_set;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        unique_a_set.insert(x);
        freq[x]++;
    }
    
    vector<int> u(unique_a_set.begin(), unique_a_set.end());
    int k = u.size();
    int max_val = u.back();

    map<int, int> counts;
    vector<int> temp_divs;
    for (int val : u) {
        get_divs(val, temp_divs);
        for (int d : temp_divs) {
            counts[d] += freq[val];
        }
    }

    vector<int> bad_counts_vec;
    for(auto const& it : counts) {
        if (n - it.second < 2) {
            bad_counts_vec.push_back(it.first);
        }
    }
    sort(bad_counts_vec.begin(), bad_counts_vec.end());

    int max_z_count = max_val;
    if (!bad_counts_vec.empty()) {
        int ptr = bad_counts_vec.size() - 1;
        while(ptr >= 0 && bad_counts_vec[ptr] == max_z_count){
            max_z_count--;
            ptr--;
        }
    }
    
    if (max_z_count == 0) {
        cout << 1 << "\n";
        return;
    }

    vector<int> suf_g(k + 1, 0);
    suf_g[k-1] = u[k-1];
    for(int i = k-2; i >= 0; --i) {
        suf_g[i] = gcd(u[i], suf_g[i+1]);
    }

    for (int z = max_z_count; z >= 1; --z) {
        auto it = lower_bound(u.begin(), u.end(), z);
        int idx = distance(u.begin(), it);
        
        if (idx == k) { // z is larger than any element in A
             // LNM condition can't be met, but this case shouldn't be reached
             // because z <= max_z_count <= max_val
             continue;
        }

        if (suf_g[idx] % z != 0) {
            cout << z << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}