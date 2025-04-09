#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;

    int count=(n/15)*3;
    int rem=n%15;
    for(int i=0;i<=rem;i++)
    {
        if(i%3==i%5)
        count++;
    }
    cout<<count<<endl;
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