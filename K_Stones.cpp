#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int mn=*min_element(a.begin(),a.end());
    int dp[k+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-a[j]>=0&&dp[i-a[j]]==0)
            dp[i]=1;
        }
    }
    if(dp[k])
    cout<<"First\n";
    else
    cout<<"Second\n";


    return 0;
}