#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
bool isvalid(int x,int y,int n,int m)
{
    return (x>=0)&&(x<n)&&(y>=0)&&(y<m);
}
void bfs(vector<string> &grid)
{
    int n=grid.size();
    int m=grid[0].size();
    int dx[]={1,-1,0,0};
    int dy[]={0,0,-1,1};
    deque<pair<int,int>> dq;
    vector<vector<int>> dist(n,vector<int>(m,inf));
    dist[0][0]=0;
    dq.push_back({0,0});
    while(!dq.empty())
    {
        int x=dq.front().first;
        int y=dq.front().second;
        dq.pop_front();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isvalid(nx,ny,n,m))
            {
                if(grid[x][y]==grid[nx][ny]&&dist[nx][ny]>dist[x][y])
                {
                    dist[nx][ny]=dist[x][y];
                    dq.push_front({nx,ny});
                }
                else if(grid[x][y]!=grid[nx][ny]&&dist[nx][ny]>dist[x][y]+1)
                {
                    dist[nx][ny]=dist[x][y]+1;
                    dq.push_back({nx,ny});
                }
            }
        }
    }
    cout<<dist[n-1][m-1]<<endl;
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
    cin>>grid[i];
    bfs(grid);

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}