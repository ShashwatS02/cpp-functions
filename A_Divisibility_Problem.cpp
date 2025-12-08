#include <iostream>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        int r=a%b;
        cout << (r? b-r: 0) << '\n';
    }
}
