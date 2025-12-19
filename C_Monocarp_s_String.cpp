#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>


using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_a = 0;
    for (char c : s) {
        if (c == 'a') {
            total_a++;
        }
    }
    int total_b = n - total_a;

    
    if (total_a == total_b) {
        cout << 0 << endl;
        return;
    }

    
    int target_balance = total_a - total_b;

    
    map<int, int> first_occurrence;
    first_occurrence[0] = 0; 

    int min_len = n;
    int current_balance = 0;

    for (int i = 0; i < n; ++i) {
        current_balance += (s[i] == 'a' ? 1 : -1);

        
        int needed_balance = current_balance - target_balance;
        
        if (first_occurrence.count(needed_balance)) {
            int start_index = first_occurrence[needed_balance];
            min_len = min(min_len, (i + 1) - start_index);
        }

        
        if (!first_occurrence.count(current_balance)) {
            first_occurrence[current_balance] = i + 1;
        }
    }

    
    if (min_len == n) {
        cout << -1 << endl;
    } else {
        cout << min_len << endl;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}