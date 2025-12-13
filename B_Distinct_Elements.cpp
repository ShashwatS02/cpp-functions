#include <iostream>
#include <vector>
#include <numeric>

// Using the namespace as requested in your saved information.
using namespace std;

// DSU find operation with path compression
int find_root(int i, vector<int>& parent) {
    if (parent[i] == i) {
        return i;
    }
    // Path compression for efficiency
    return parent[i] = find_root(parent[i], parent);
}

// DSU unite operation
void unite_nodes(int i, int j, vector<int>& parent) {
    int root_i = find_root(i, parent);
    int root_j = find_root(j, parent);
    if (root_i != root_j) {
        parent[root_j] = root_i;
    }
}

void solve_test_case() {
    int n;
    cin >> n;

    // Use 0-based indexing for the input array b
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    // This will store the 0-based index of the previous occurrence
    vector<int> prev_occurrence_link(n);

    // For a[0], there is no previous element. We use -1 to signify this.
    prev_occurrence_link[0] = -1;

    // Calculate the links for the rest of the array
    for (int i = 1; i < n; ++i) {
        // The core recurrence relation, adapted for 0-based indices.
        // b_i (1-based) is b[i-1] (0-based)
        // b_{i-1} (1-based) is b[i-2] (0-based)
        // i (1-based) is i
        long long b_current = b[i];
        long long b_previous = b[i-1];
        // The result 'p' is a 1-based index from the formula
        int p_1_based = (int)(b_previous - b_current + (i + 1));
        // Convert the resulting 1-based index to a 0-based index
        prev_occurrence_link[i] = p_1_based - 1;
    }

    // Initialize DSU parent array for n elements (0 to n-1)
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    // Group elements into components based on their links
    for (int i = 0; i < n; ++i) {
        if (prev_occurrence_link[i] != -1) {
            unite_nodes(i, prev_occurrence_link[i], parent);
        }
    }

    vector<int> a(n);
    // Maps the root of a component to its assigned value
    vector<int> root_value_map(n, 0);
    int next_available_val = 1;
    
    // Assign a unique value to each component
    for (int i = 0; i < n; ++i) {
        int r = find_root(i, parent);
        if (root_value_map[r] == 0) {
            root_value_map[r] = next_available_val++;
        }
        a[i] = root_value_map[r];
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O for performance in contests.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_test_case();
    }
    return 0;
}