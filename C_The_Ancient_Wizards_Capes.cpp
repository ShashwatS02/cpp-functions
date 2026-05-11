#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve_capes_arrangement() {
    int num_wizards;
    cin >> num_wizards;
    vector<long long> visibility_list(num_wizards);
    for (int i = 0; i < num_wizards; ++i) {
        cin >> visibility_list[i];
    }

    if (num_wizards == 1) {
        if (visibility_list[0] == 1) {
            cout << 2 << "\n";
        } else {
            cout << 0 << "\n";
        }
        return;
    }

    int valid_arrangements = 0;

    
    for (int first_wizard_choice = 0; first_wizard_choice <= 1; ++first_wizard_choice) {
        vector<int> choices(num_wizards);
        choices[0] = first_wizard_choice; 
        bool possible = true;

        
        for (int i = 1; i < num_wizards; ++i) {
            long long s = visibility_list[i] - visibility_list[i - 1] + 1;
            int next_choice = s - choices[i - 1];

            if (next_choice != 0 && next_choice != 1) {
                possible = false;
                break;
            }
            choices[i] = next_choice;
        }

        if (!possible) {
            continue;
        }

        
        long long right_cape_count = 0;
        for (int choice : choices) {
            if (choice == 0) {
                right_cape_count++;
            }
        }

        
        if (visibility_list[0] == (long long)choices[0] + right_cape_count) {
            valid_arrangements++;
        }
    }

    cout << valid_arrangements << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve_capes_arrangement();
    }

    return 0;
}