#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][2][4];
int f(int ind,int tight,int nonz,string &num)
{
    if(nonz<0)
    return 0;
    if(ind==num.size())
    return (nonz>=0);
    if(dp[ind][tight][nonz]!=-1)
    return dp[ind][tight][nonz];
    int res=0;
    int ub=tight?(num[ind]-'0'):9;
    for(int i=0;i<=ub;i++)
    {
        res+=f(ind+1,tight&&(i==ub),nonz-(i!=0),num);
    }
    return dp[ind][tight][nonz]=res;

}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        memset(dp,-1,sizeof(dp));
        string R=to_string(r);
        string L=to_string(l-1);
        int ans2=f(0,1,3,R);
        memset(dp,-1,sizeof(dp));
        int ans1=f(0,1,3,L);
        int ans=ans2-ans1;
        cout<<ans<<endl;
    }
    

    return 0;
}