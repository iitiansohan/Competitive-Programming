#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isleaf(int u,vector<vector<int>> &adj)
{
    if(adj[u].size()==0)
    return true;
    else
    return false;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++)
    {
        int e;
        cin>>e;
        adj[e].push_back(i);
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        int count=0;
        for(auto ch:adj[i])
        {
            if(isleaf(ch,adj))
            count++;
        }
        if(adj[i].size()==0||count>=3)
        continue;
        else
        {
            flag=false;
            break;
        }
    }
    if(flag)
    cout<<"Yes\n";
    else
    cout<<"No\n";

    return 0;
}