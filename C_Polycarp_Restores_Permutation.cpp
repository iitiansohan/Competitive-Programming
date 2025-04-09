#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> q(n-1);
    for(int i=0;i<n-1;i++)
    {
        cin>>q[i];
    }
    vector<int> p1(n);
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        p1[i]=sum;
        sum+=q[i];
    }
    p1[n-1]=sum;
    int mn=INT_MAX;
    for(int i=0;i<n;i++)
    mn=min(mn,p1[i]);
    int x=1-mn;
    vector<int> p(n);
    for(int i=0;i<n;i++)
    p[i]=p1[i]+x;
    sort(p.begin(),p.end());

    bool flag=true;
    for(int i=1;i<n;i++)
    {
        if(p[i]-p[i-1]!=1)
        {
            flag=false;
            break;
        }
    }
    if(!flag)
    cout<<-1<<endl;
    else
    {
        for(int i=0;i<n;i++)
        cout<<p1[i]+x<<" ";
    }
    cout<<endl;




    return 0;
}