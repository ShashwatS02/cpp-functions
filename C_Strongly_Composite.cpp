#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        map<int,int> m;
        for(auto x : a){
            int v = x;
            for(int d = 2; d*d <= v; d++){
                while(v % d == 0) m[d]++, v /= d;
            }
            if(v > 1) m[v]++;
        }
        int p = 0, r = 0;
        for(auto &c : m){
            p += c.second / 2;
            r += c.second % 2;
        }
        p += r / 3;
        cout << p << "\n";
    }
}
