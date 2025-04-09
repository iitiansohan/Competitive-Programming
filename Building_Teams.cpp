#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &graph,int u,int p,vector<int> &color)
{
    for(auto v:graph[u])
    {
        if(v==p)
        continue;
        if(color[v]!=-1)
        {
            if(color[v]==color[u])
            return false;

        }
        if(color[v]==-1)
        {
            color[v]=color[u]^1;
            bool valid=dfs(graph,v,u,color);
            if(valid==false)
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> color(n+1,-1);
    int ans=true;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            ans&=dfs(graph,i,0,color);
        }
    }
    if(ans==false)
    cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=1;i<=n;i++)
        {
            cout<<color[i]+1<<" ";
        }
    }
    return 0;
}