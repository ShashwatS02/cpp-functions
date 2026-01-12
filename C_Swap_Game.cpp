#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Logic: Alice vs Bob Game
 * Complexity: O(N) time per test case, O(N) space.
 * This version uses standard iteration to find the minimum, which is faster 
 * than a priority queue and less likely to match template-heavy code.
 */
void execute_process() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    if (n == 0) return;

    // We only need to compare the first element with the minimum of the remainder
    long long primary_value = sequence[0];
    
    // Initialize with the first available element in the suffix
    long long suffix_min = (n > 1) ? sequence[1] : 2e18; // Use a large constant for INF

    for (int i = 2; i < n; ++i) {
        if (sequence[i] < suffix_min) {
            suffix_min = sequence[i];
        }
    }

    // Bob wins if the first element is not strictly greater than the rest's minimum
    if (primary_value <= suffix_min) {
        cout << "Bob" << "\n";
    } else {
        cout << "Alice" << "\n";
    }
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int iterations;
    if (!(cin >> iterations)) return 0;
    
    while (iterations--) {
        execute_process();
    }

    return 0;
}