#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    sort(arr.begin(),arr.end());
    int low=0,high=n-1;
    for(int i=n-1;i>n-1-k;i--)
    {
        s-=arr[i];
    }
    int ans=s;
    for(int i=n-k;i<n;i++)
    {
        s+=arr[i];
        s-=arr[low]+arr[low+1];
        low+=2;
        ans=max(ans,s);
    }
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