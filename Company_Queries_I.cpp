#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int up[N][20];
void dfs(int u,int p,vector<vector<int>> &adj)
{
    up[u][0]=p;
    for(int i=1;i<20;i++)
    {
        int halfpar=up[u][i-1];
        up[u][i]=(halfpar==-1)?-1:up[halfpar][i-1];
    }
    for(auto ch:adj[u])
    {
        if(ch==p)
        continue;
        dfs(ch,u,adj);
    }
}
int kthans(int v,int k)
{
    for(int i=0;i<20;i++)
    {
        if(v==-1) return v;
        if(k&(1<<i)){
            v=up[v][i];
            k-=(1<<i);
        }
    }
    return v;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++)
    {
        int e;
        cin>>e;
        adj[i].push_back(e);
        adj[e].push_back(i);
    }
    dfs(1,-1,adj);
    for(int i=0;i<q;i++)
    {
        int x,k;
        cin>>x>>k;
        cout<<kthans(x,k)<<endl;
    }

    

    return 0;
}