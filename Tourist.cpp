#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void find_closest_attraction() {
    int attraction_count;
    long long chef_x_coord, chef_y_coord;
    cin >> attraction_count >> chef_x_coord >> chef_y_coord;

    long long min_required_distance = -1;

    for (int i = 0; i < attraction_count; ++i) {
        long long attr_x, attr_y;
        cin >> attr_x >> attr_y;

        long long current_distance = abs(chef_x_coord - attr_x) + abs(chef_y_coord - attr_y);

        if (min_required_distance == -1 || current_distance < min_required_distance) {
            min_required_distance = current_distance;
        }
    }

    cout << min_required_distance << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        find_closest_attraction();
    }

    return 0;
}