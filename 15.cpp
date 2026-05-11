#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define print(i) cout << i << endl;
#define RE return

/**
 * build() solves the problem of moving all '*' to be consecutive
 * with the minimum total cost by centering them around the median star.
 */
void build() {
    int n;
    if (!(cin >> n)) RE;
    string s;
    cin >> s;

    // 1. Count total number of stars
    int total_stars = 0;
    for (char c : s) {
        if (c == '*') total_stars++;
    }

    // Edge case: if there are no stars or just one, no moves are needed
    if (total_stars <= 1) {
        print(0);
        RE;
    }

    // 2. Find the position of the median star
    int target_star_index = (total_stars + 1) / 2;
    int pos = -1, curr_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            curr_count++;
            if (curr_count == target_star_index) {
                pos = i; // This is our anchor point
                break;
            }
        }
    }

    int total_moves = 0;
    int stars_seen = 0;

    // 3. Calculate moves for stars to the left of the median
    for (int i = 0; i < pos; i++) {
        if (s[i] == '*') {
            // They should move to: pos - (remaining_stars_to_the_left)
            total_moves += (pos - i - (target_star_index - stars_seen - 1));
            stars_seen++;
        }
    }

    // 4. Calculate moves for stars to the right of the median
    stars_seen = 0;
    for (int i = pos + 1; i < n; i++) {
        if (s[i] == '*') {
            stars_seen++;
            // They should move to: pos + stars_seen
            total_moves += (i - (pos + stars_seen));
        }
    }

    print(total_moves);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (!(cin >> t)) t = 1;
    while (t--) {
        build();
    }
    RE 0;
}
