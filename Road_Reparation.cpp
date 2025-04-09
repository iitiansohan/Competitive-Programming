#include <bits/stdc++.h>
using namespace std;
#define int long long
int par[100005];
int rnk[100005];
void make_set(int n)
{
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        rnk[i]=1;
    }
}
int find_set(int x)
{
    if(par[x]==x)
    return x;
    return par[x]=find_set(par[x]);
}
void union_set(int a,int b)
{
    int p1=find_set(a);
    int p2=find_set(b);
    if(p1==p2)
    return;
    if(rnk[p1]>rnk[p2])
    {
        par[p2]=p1;
        rnk[p1]+=rnk[p2];
    }
    else
    {
        par[p1]=p2;
        rnk[p2]+=rnk[p1];
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> roads(m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        roads[i]={c,{a,b}};
    }
    sort(roads.begin(),roads.end());
    make_set(n);
    int roadC=0;
    int cost=0;
    for(int i=0;i<m;i++)
    {
        int curW=roads[i].first;
        int a=roads[i].second.first;
        int b=roads[i].second.second;
        if(find_set(a)==find_set(b))
        continue;
        roadC++;
        cost+=curW;
        union_set(a,b);

    }
    if(roadC!=n-1)
    cout<<"IMPOSSIBLE\n";
    else{
        cout<<cost<<endl;
    }

    return 0;
}