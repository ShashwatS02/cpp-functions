#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    for(char c : s) {
        c = tolower(c);
        if(string("aeiouy").find(c) == string::npos)
            cout << '.' << c;
    }
    cout << '\n';
}
