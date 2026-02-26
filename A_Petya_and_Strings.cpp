#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    for(char &c : a) c = tolower(c);
    for(char &d : b) d = tolower(d);
    cout << (a > b ? 1 : a < b ? -1 : 0) << '\n';
}
