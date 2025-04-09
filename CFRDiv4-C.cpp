#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    cin >> arr[i];
    int sum=0,m=0,ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        m=max(arr[i],m);
        if(sum==2*m)
        ans++;
    }
    cout << ans << endl;
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
