#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> dist(n+1,inf);
    vector<int> par(n+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//{weight,node}
    pq.push({0,1});
    dist[1]=0,par[1]=1;
    while(!pq.empty())
    {
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(d>dist[u]) continue;
        for(auto ch: adj[u])
        {
            int v=ch.first;
            int wt=ch.second;
            if(dist[v]>wt+dist[u])
            {
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
                par[v]=u;
            }
        }
    }
    bool flag=true;
    if(dist[n]==inf)
    cout<<-1<<endl;
    else
    {
        int v=n;
        vector<int> ans;
        while(par[v]!=v)
        {
            ans.push_back(v);
            v=par[v];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}