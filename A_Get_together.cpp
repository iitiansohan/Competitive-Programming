#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const ld eps=1e-6;
bool canmeet(vector<int> &x,vector<int> &v,double t)
{
    ld left=INT_MIN,right=INT_MAX;
    for(int i=0;i<x.size();i++)
    {
        ld leftseg=x[i]-t*v[i];
        ld rightseg=x[i]+t*v[i];
        left=max(left,leftseg);
        right=min(right,rightseg);
    }
    return left<=right;
}
int32_t main() {
    cout<<fixed<<setprecision(6)<<endl;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int> pos(n),vel(n);
    for(int i=0;i<n;i++)
    cin>>pos[i]>>vel[i];
    ld low=0,high=1e9;
    ld ans=high;
    int count=0;
    while(high-low>=eps&&count<=100)
    {
        ld mid=low+(high-low)/2.0;
        if(canmeet(pos,vel,mid))
        {
            high=mid;
            ans=mid;
        }
        else
        low=mid;
        count++;
    }
    cout<<ans<<endl;
    return 0;
}