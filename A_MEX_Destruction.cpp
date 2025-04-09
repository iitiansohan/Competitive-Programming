#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (!a.empty() && a.back() == 0)
        a.pop_back();

    reverse(a.begin(), a.end());
    while (!a.empty() && a.back() == 0)
        a.pop_back();
    // reverse(a.begin(), a.end());

    if (a.empty())
    {
        cout << 0 << '\n';
        return;
    }

    bool hasZero = false;
    for (const auto x : a)
    {
        if(x==0)
        {hasZero=1;break;}
    }
    if (hasZero)
        cout << 2 << '\n';
    else
        cout << 1 << '\n';
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
