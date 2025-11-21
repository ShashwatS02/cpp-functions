#include <iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long t = (n + 1) >> 1;
    cout << (k <= t ? (k << 1) - 1 : ((k - t) << 1)) << '\n';
    return 0;
}
