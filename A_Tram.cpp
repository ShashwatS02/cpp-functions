#include <iostream>
using namespace std;
int main() {
    int n, in, out, curr = 0, mx = 0;
    cin >> n;
    while(n--) {
        cin >> out >> in;
        curr -= out;
        curr += in;
        if(curr > mx) mx = curr;
    }
    cout << mx << '\n';
}
