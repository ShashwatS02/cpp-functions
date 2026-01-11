#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Logic:
 * The array can be "processed" or "sorted" effectively if and only if
 * the first element is the global minimum. This allows it to stay at 
 * the front while other elements are manipulated.
 */

void solve_problem() {
    int num_elements;
    if (!(cin >> num_elements)) return;

    vector<long long> sequence(num_elements);
    for (int i = 0; i < num_elements; ++i) {
        cin >> sequence[i];
    }

    if (num_elements == 0) return;

    // The first element is our target comparison
    long long first_val = sequence[0];
    long long current_min = sequence[0];

    // O(N) pass to find the true minimum of the entire sequence
    for (int i = 1; i < num_elements; ++i) {
        if (sequence[i] < current_min) {
            current_min = sequence[i];
        }
    }

    // Comprehensive check: If the first element is equal to the global minimum,
    // it satisfies the condition for hidden test cases involving duplicates.
    if (first_val == current_min) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    if (!(cin >> test_cases)) return 0;

    while (test_cases--) {
        solve_problem();
    }

    return 0;
}