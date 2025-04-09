#include<bits/stdc++.h>
using namespace std;   
#define int long long
#define vi vector<int>
#define all(v) v.begin(), v.end()

int minv(const vi &v) {
    return *min_element(all(v));
}

int maxv(const vi &v) {
    return *max_element(all(v));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    int low = minv(a), high = maxv(b), ans = 1e18;
    if(minv(a)>=maxv(b))
    {
        ans=0;
    }
    else
    {

    // Ternary Search
    while (high - low > 3) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        
        int cost1 = 0, cost2 = 0;
        for (int i = 0; i < n; i++) {
            cost1 += max(0LL, mid1 - a[i]);
            cost2 += max(0LL, mid2 - a[i]);
        }
        for (int i = 0; i < m; i++) {
            cost1 += max(0LL, b[i] - mid1);
            cost2 += max(0LL, b[i] - mid2);
        }

        if (cost1 <= cost2)
            high = mid2 - 1;
        else
            low = mid1 + 1;
    }

    // Final Check within the narrowed range
    for (int i = low; i <= high; i++) {
        int cost = 0;
        for (int j = 0; j < n; j++) {
            cost += max(0LL, i - a[j]);
        }
        for (int j = 0; j < m; j++) {
            cost += max(0LL, b[j] - i);
        }
        ans = min(ans, cost);
    }}

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
