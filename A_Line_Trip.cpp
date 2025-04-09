#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int mx=0;
    for(int i=1;i<n;i++)
    {
        mx=max(mx,arr[i]-arr[i-1]);
    }
    mx=max(mx,2*(x-arr[n-1]));
    mx=max(arr[0],mx);
    cout<<mx<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}