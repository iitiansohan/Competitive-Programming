#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &graph,int n)
{
    vector<bool> visited(n+1,false);
    // int count=0;
    vector<int> order;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            order.push_back(i);
            queue<int> q;
            q.push(i);
            visited[i]=true;
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
                    }
                }
            }
        }
    }
    cout<<order.size()-1<<endl;
    int size=order.size();
    for(int i=0;i<size-1;i++)
    {
        cout<<order[i]<<" "<<order[i+1]<<endl;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges(m);
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