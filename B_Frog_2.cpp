#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++)
    cin>>h[i];
    //dp[i]=number of ways to reach ith stone
    //dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]))
    vector<int> dp(n+1);
    dp[1]=0;
    dp[2]=abs(h[2]-h[1]);
    for(int i=3;i<=n;i++)
    {
        int mn=INT_MAX;
        for(int j=1;i-j>=1&&j<=k;j++)
        mn=min(mn,dp[i-j]+abs(h[i]-h[i-j]));
        // dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
        dp[i]=mn;
    }

    cout<<dp[n]<<endl;
    

    return 0;
}