#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s;
    vector<char> v;
    for (char c : s)
        if (c != '+') v.push_back(c);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if (i) cout << '+';
        cout << v[i];
    }
    cout << '\n';
}
