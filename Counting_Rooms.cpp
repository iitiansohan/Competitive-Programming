#include <bits/stdc++.h>
using namespace std;
bool isvalid(int i,int j,int n,int m)
{
    return (i>=0)&&(i<n)&&(j>=0)&&(j<m);
}
int bfs(vector<vector<char>> &grid)
{
    int dx[]={1,-1,0,0};
    int dy[]={0,0,-1,1};
    int n=grid.size();
    int m=grid[0].size();
    bool vis[n][m];
    int count=0;
    memset(vis,0,sizeof(vis));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='#')
            continue;
            if(vis[i][j]==1)
            continue;
            count++;
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j]=true;
            while(!q.empty())
            {
                auto u=q.front();
                int x=u.first;
                int y=u.second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int ni=x+dx[k];
                    int nj=y+dy[k];
                    if(isvalid(ni,nj,n,m)&&grid[ni][nj]=='.'&&!vis[ni][nj])
                    {
                        q.push({ni,nj});
                        vis[ni][nj]=true;
                    }
                }
            }
        }
    }
    return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>grid[i][j];
    }
    //. = floor
    //# = wall
    cout<<bfs(grid)<<endl;

    return 0;
}