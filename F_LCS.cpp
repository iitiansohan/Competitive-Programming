#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int j=0;j<=m;j++)
    dp[0][j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans+=a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto ch:ans)
    cout<<ch;
    cout<<endl;
    return 0;
}