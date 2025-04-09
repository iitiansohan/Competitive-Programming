#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[18][2][180];
int f(int ind,bool tight,int sum,string &num)
{
    if(ind==num.size())
    return sum;
    if(dp[ind][tight][sum]!=-1)
    return dp[ind][tight][sum];
    int ub=tight?num[ind]-'0':9;
    int res=0;
    for(int i=0;i<=ub;i++)
    {
        res+=f(ind+1,tight&(i==ub),sum+i,num);
    }
    return dp[ind][tight][sum]=res;
}
void solve() {
    int a,b;
    cin>>a>>b;
    string R=to_string(b);
    memset(dp,-1,sizeof(dp));
    int rightans=f(0,1,0,R);
    string L=to_string(a-1);
    memset(dp,-1,sizeof(dp));
    int leftans=(a==0)?0:f(0,1,0,L);
    int ans=rightans-leftans;
    cout<<ans<<endl;
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