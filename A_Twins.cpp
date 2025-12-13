#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x = 0, y = 0, z = 0;
    cin >> n;
    int a[101];
    for(int i = 0; i < n; ++i) cin >> a[i], x += a[i];
    x /= 2;
    sort(a, a + n);
    for(int i = n; y <= x; ) y += a[--i], ++z;
    cout << z << '\n';
}
