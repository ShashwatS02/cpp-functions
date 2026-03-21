#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while(T--){
        int N,Q; cin>>N>>Q;
        vector<int> par(N+1); par[1]=0;
        for(int i=2;i<=N;i++) cin>>par[i];
        vector<vector<int>> ch(N+1);
        for(int v=2;v<=N;v++) ch[par[v]].push_back(v);
        
        vector<int> dep(N+1,0);
        int L = 18;
        vector<vector<int>> up(N+1, vector<int>(L,0));
        function<void(int)> dfs=[&](int v){
            for(int u:ch[v]){
                dep[u]=dep[v]+1;
                up[u][0]=v;
                for(int j=1;j<L;j++) up[u][j]=up[up[u][j-1]][j-1];
                dfs(u);
            }
        };
        dep[1]=1; dfs(1);
        
        auto lca=[&](int u,int v)->int{
            if(dep[u]<dep[v]) swap(u,v);
            int d=dep[u]-dep[v];
            for(int j=0;j<L;j++) if(d>>j&1) u=up[u][j];
            if(u==v) return u;
            for(int j=L-1;j>=0;j--) if(up[u][j]!=up[v][j]) u=up[u][j], v=up[v][j];
            return up[u][0];
        };
        
        set<int> S;
        long long score=0;
        
        vector<int> sub;
        function<void(int)> collect=[&](int v){
            sub.push_back(v);
            for(int u:ch[v]) collect(u);
        };
        
        for(int q=0;q<Q;q++){
            int X; cin>>X;
            sub.clear(); collect(X);
            for(int y:sub){
                if(S.count(y)){
                    for(int w:S) if(w!=y) score -= dep[lca(y,w)];
                    S.erase(y);
                }else{
                    for(int w:S) score += dep[lca(y,w)];
                    S.insert(y);
                }
            }
            if(q) cout<<' ';
            cout<<score;
        }
        cout<<'\n';
    }
    return 0;
}
