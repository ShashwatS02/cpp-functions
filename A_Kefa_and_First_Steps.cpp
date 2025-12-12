#include<iostream>
using namespace std;
int main(){
    int n, a, b, res=1, curr=1;
    cin>>n>>a;
    while(--n){
        cin>>b;
        curr = b>=a ? curr+1 : 1;
        if(curr>res) res=curr;
        a=b;
    }
    cout<<res<<'\n';
}
