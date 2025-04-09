
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>

void solve() {
    int n;
    cin >> n;
    vi a(2 * n);
    int c1 = 0,c0=1;
    
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            c1++;
        else
            c0++;
    }
    
    int mn = c1 % 2;
    int mx = min(2*n-c1, c1);
    
    cout << mn << " " << mx << endl;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
