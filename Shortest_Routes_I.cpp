#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    vector<int> dist(n+1,INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d>dist[u]) continue;
        for(auto x:graph[u])
        {
            int v=x.first;
            int wt=x.second;
            if(dist[v]>dist[u]+wt)
            {
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INF) cout<<-1<<" ";
        else
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}