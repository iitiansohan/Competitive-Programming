#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> dp;
vector<int> a;
int helper(int i,int j,int t)
{
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    a.resize(n);
    dp.resize(n,vector<vector<int>>(n,vector<int>(2,INT_MIN)));
    for(int i=0;i<n;i++)
    cin>>a[i];
    int ans=helper(0,n-1,0);
    cout<<ans<<endl;
    return 0;
}