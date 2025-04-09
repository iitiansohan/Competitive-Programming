#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;
    vector<int> arr (n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    int x=sqrt(sum);
    bool flag=false;
    if(x*x==sum)
    flag=true;
    if(flag)
    cout<<"YES\n";
    else
    cout<<"NO\n";
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