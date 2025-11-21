#include<iostream>
using namespace std;

int main() {
    int a, b, cnt = 0;
    cin >> a >> b;
    while (a <= b) {
        a *= 3;
        b <<= 1;
        ++cnt;
    }
    cout << cnt;
    return 0;
}
