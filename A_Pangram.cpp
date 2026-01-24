#include<iostream>
using namespace std;
int main() {
    int n, a[26]={};
    string t;
    cin>>n>>t;
    for(auto c:t) a[(c|32)-'a']|=(c>='A'&&c<='Z'||c>='a'&&c<='z');
    int f=1;
    for(int x=0;x<26;++x) f&=a[x];
    cout<<(f?"YES":"NO")<<endl;
}
