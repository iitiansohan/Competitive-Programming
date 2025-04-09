#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum(int x, int n) {
    int m = n / x;
    return x * m * (m + 1) / 2; 
}

void solve() {
    int n;
    cin >> n;

    int max_sum = sum(2, n);
    int ans = 2;

    for (int i = 3; i <= n; ++i) {
        int current_sum = sum(i, n);
        if (current_sum > max_sum) {
            max_sum = current_sum;
            ans = i;
        }
    }

    cout << ans << endl;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
