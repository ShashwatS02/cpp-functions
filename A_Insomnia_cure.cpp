#include <iostream>
using namespace std;

int main() {
    int a[4], d;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> d;
    int cnt = 0;
    for(int i = 1; i <= d; ++i) {
        if(!(i % a[0] && i % a[1] && i % a[2] && i % a[3])) ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}
