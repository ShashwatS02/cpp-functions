#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


void solve_problem() {
    int n;
    cin >> n;
    
    
    int max_val = INT_MIN;
    
    for (int i = 0; i < n; ++i) {
        int current_element;
        cin >> current_element;
        
        if (current_element > max_val) {
            max_val = current_element;
        }
    }
    
    cout << max_val << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve_problem();
    }
    
    return 0;
}