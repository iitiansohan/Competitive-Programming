#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &graph,int n)
{
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,-1);
    queue<int> q;
    q.push(1);
    visited[1]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:graph[u])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
                parent[v]=u;
            }
        }
    }
    
    if(visited[n]==false)
    cout<<"IMPOSSIBLE\n";
    else{
        vector<int> path;
        int curr=n;
        path.push_back(curr);
        while(curr!=1)
        {
            path.push_back(parent[curr]);
            curr=parent[curr];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(auto p:path)
        cout<<p<<" ";
        cout<<endl;
    }
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
    bfs(graph,n);

    return 0;
}