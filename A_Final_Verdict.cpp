#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    if(sum/n==x&&sum%n==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
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