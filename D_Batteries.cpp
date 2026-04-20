#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,cand=1;
        cin>>n;
        for(int i=2;i<=n;i++){
            cout<<cand<<" "<<i<<endl;
            int ans;
            cin>>ans;
            if(ans==1)break;
            cand=i;
        }
    }
}
