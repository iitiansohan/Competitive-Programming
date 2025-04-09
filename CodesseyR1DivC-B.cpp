#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int power;
    cin>>power;
    if(power<=1399)
    cout<<"Division 4\n";
    else if(power<=1599)
    cout<<"Division 3\n";
    else if(power<=1899)
    cout<<"Division 2\n";
    else
    cout<<"Division 1\n";
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