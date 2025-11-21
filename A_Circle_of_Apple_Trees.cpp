#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void perform_computation() {
    int num_trees;
    cin >> num_trees;

    
    vector<int> beauty_marker(num_trees + 1, 0);

    for (int i = 0; i < num_trees; ++i) {
        int current_beauty;
        cin >> current_beauty;
        
        
        if (current_beauty <= num_trees) {
            beauty_marker[current_beauty] = 1;
        }
    }

    
    int eatable_apples = 0;
    for (int i = 1; i <= num_trees; ++i) {
        if (beauty_marker[i] == 1) {
            eatable_apples++;
        }
    }

    cout << eatable_apples << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case_count;
    cin >> test_case_count;
    while (test_case_count--) {
        perform_computation();
    }

    return 0;
}