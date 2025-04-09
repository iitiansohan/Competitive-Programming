#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> a(n);
    int sum=0;
    vector<int> pre(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        pre[i]=sum;
    }
    int ans=0;
    if(a[0]==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        ans=max(pre[i]-i,ans);
    }
    cout<<ans<<endl;


    return 0;
}