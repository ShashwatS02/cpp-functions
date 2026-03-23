#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Logic: Assigns an integer value to each size.
 * - S: Negative values (the more 'X's, the smaller it is)
 * - M: Zero
 * - L: Positive values (the more 'X's, the larger it is)
 */
int getSizeValue(string s) {
    char base = s.back();
    int x_count = s.size() - 1;

    if (base == 'M') {
        return 0;
    } else if (base == 'L') {
        // Large sizes: L=1, XL=2, XXL=3, etc.
        return 1 + x_count;
    } else {
        // Small sizes: S=-1, XS=-2, XXS=-3, etc.
        return -(1 + x_count);
    }
}

void solve_tshirt_comparison() {
    string a, b;
    if (!(cin >> a >> b)) return;

    int valA = getSizeValue(a);
    int valB = getSizeValue(b);

    if (valA < valB) {
        cout << "<" << endl;
    } else if (valA > valB) {
        cout << ">" << endl;
    } else {
        cout << "=" << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve_tshirt_comparison();
    }
    return 0;
}