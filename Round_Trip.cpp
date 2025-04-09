#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &graph,int u,vector<int> &par,vector<int> &visited,vector<int> &path,int &start,int &end)
{
    visited[u]=true;
    path.push_back(u);
    for(auto v:graph[u])
    {
        if(!visited[v])
        {
            par[v]=u;
            bool flag=dfs(graph,v,par,visited,path,start,end);
            if(flag) return true;
        }
        else if(v!=par[u])
        {
            start=v;
            end=u;
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> path;
    vector<int> visited(n+1,0);
    vector<int> par(n+1,0);
    int start=0,end=0;
    bool flag=false;
    // bool flag=dfs(graph,1,par,visited,path,start,end);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            flag=dfs(graph,i,par,visited,path,start,end);
            if(flag)
            break;
        }
    }
    if(!flag)
    cout<<"IMPOSSIBLE\n";
    else
    {
        bool counter=false;
        vector<int> cycle;
        for(auto x:path)
        {
            if(x==start)
            counter=true;
            if(counter)
            {
                cycle.push_back(x);
                // cout<<x<<" ";
            }
            if(x==end)
            break;
        }
        cycle.push_back(start);
        // cout<<start<<endl;
        cout<<cycle.size()<<endl;
        for(auto x:cycle)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}
