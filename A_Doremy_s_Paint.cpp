#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

void build(){
    int n; cin >> n;
    vi v(n);
    for(auto &i : v) cin >> i;
    // Replace below line with your actual logic
    cout << 1 << " " << n << endl;
}

int main(){
    int t; cin >> t;
    while(t--) build();
    return 0;
}
