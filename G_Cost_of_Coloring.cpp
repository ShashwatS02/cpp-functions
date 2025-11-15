#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    long long MOD = 998244353;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}

const int MAX_SIZE = 4005;
long long fact[MAX_SIZE];
long long invFact[MAX_SIZE];
long long MOD = 998244353;

void precompute_combi(int N) {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr_mod_p(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

// Calculates ways to color 'items' with exactly 'colors' (k! * S(items, colors))
// using Principle of Inclusion-Exclusion
long long count_surjective_maps(int items, int colors, const vector<vector<long long>>& pows) {
    if (items < colors) return 0;
    long long total = 0;
    for (int p = 0; p <= colors; ++p) {
        long long term = (pows[p][items] * nCr_mod_p(colors, p)) % MOD;
        if ((colors - p) % 2 == 1) {
            total = (total - term + MOD) % MOD;
        } else {
            total = (total + term) % MOD;
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    precompute_combi(n + m);

    // Precompute all necessary powers to speed up calculations
    vector<vector<long long>> powers(k + 1, vector<long long>(max(n, m) + 1));
    for(int p = 0; p <= k; ++p) {
        powers[p][0] = 1;
        for(int i = 1; i <= max(n, m); ++i) {
            powers[p][i] = (powers[p][i-1] * p) % MOD;
        }
    }

    for (int v = 1; v <= n + m - 1; ++v) {
        if (v < min(n, m)) continue;

        long long ans_v = 0;
        long long color_sequences = nCr_mod_p(v - 1, k - 1);

        // Case 1: Paint i=n rows and j=v-n columns
        if (v >= n) {
            int i = n;
            int j = v - n;
            if (j >= 0 && j < m) { // j must be < m, otherwise value is not v
                long long ways_to_color_rows = count_surjective_maps(i, k, powers);
                long long term = (nCr_mod_p(m, j) * ways_to_color_rows) % MOD;
                ans_v = (ans_v + term) % MOD;
            }
        }
        
        // Case 2: Paint j=m columns and i=v-m rows
        if (v >= m) {
            int j = m;
            int i = v - m;
            if (i >= 0 && i < n) { // i must be < n
                long long ways_to_color_cols = count_surjective_maps(j, k, powers);
                long long term = (nCr_mod_p(n, i) * ways_to_color_cols) % MOD;
                ans_v = (ans_v + term) % MOD;
            }
        }
        
        cout << (ans_v * color_sequences) % MOD << " ";
    }
    cout << endl;

    return 0;
}