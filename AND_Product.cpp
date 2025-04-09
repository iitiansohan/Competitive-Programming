#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int a,b;
    cin>>a>>b;
    int num=0;
    int c=0;
    while(a!=b)
    {
        a=a>>1;
        b=b>>1;
        c++;
    }
    cout<<(a<<c)<<endl;
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