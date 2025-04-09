#include <bits/stdc++.h>
using namespace std;
bool isvalid(int i,int j,int n,int m)
{
    return (i>=0)&&(i<n)&&(j>=0)&&(j<m);
}
void bfs(vector<vector<char>> &grid)
{
    int n=grid.size();
    int m=grid[0].size();
    int x,y;
    int ix,iy;
    bool breakAll=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='A')
            {
                ix=i;
                iy=j;
                breakAll=true;
                break;
            }
        }
        if(breakAll)
        break;
    }
    int fx,fy;
    breakAll=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='B')
            {
                fx=i;
                fy=j;
                breakAll=true;
                break;
            }
        }
        if(breakAll)
        break;
    }
    vector<vector<bool>> visited(n,vector<bool> (m));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>> (m,{-1,-1}));
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    queue<pair<int,int>> q;
    q.push({ix,iy});
    visited[ix][iy]=true;
    int count=0;
    bool found=false;
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        x=u.first;
        y=u.second;
        visited[x][y]=true;
        if(grid[x][y]=='B')
        {
            found=true;
            break;
        }    
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isvalid(nx,ny,n,m)&&grid[nx][ny]!='#'&&!visited[nx][ny])
            {
                q.push({nx,ny});
                visited[nx][ny]=true;
                parent[nx][ny]={x,y};
            }
        }
        if(found)
        break;
    }
    if(found)
    {
        cout<<"YES"<<endl;
        pair<int,int> curr={fx,fy};
        vector<char> path;
        while(curr!= make_pair(ix,iy))
        {
            int delx=curr.first-parent[curr.first][curr.second].first;
            int dely=curr.second-parent[curr.first][curr.second].second;
            if(dely==1)
            path.push_back('R');
            else if(dely==-1)
            path.push_back('L');
            else if(delx==1)
            path.push_back('D');
            else
            path.push_back('U');
            curr=parent[curr.first][curr.second];
        }
        cout<<path.size()<<endl;
        reverse(path.begin(),path.end());
        for(auto p:path)
        cout<<p;
        
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
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
    //A = start
    //B = end
    bfs(grid);

    return 0;
}