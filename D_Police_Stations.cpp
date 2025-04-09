#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k,d;
    cin>>n>>k>>d;
    queue<int> q;
    vector<int> dist(n+1,INF);
    vector<int> vis(n+1,0);
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        q.push(x);
        vis[x]=1;
    }
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
    }
    vector<int> keep(n-1,0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(auto v:graph[u])
        {
            if(vis[v.first]==0)
            {
                q.push(v.first);
                keep[v.second]=1;
                vis[v.first]=1;
            }
        }
    }
    int ans=0;
    for(auto x:keep)
    {
        if(x==0) ans++;
    }
    cout<<ans<<endl;
    for(int i=0;i<n-1;i++)
    {
        if(keep[i]==0)
        cout<<i+1<<" ";
    }
    cout<<endl;


    return 0;
}