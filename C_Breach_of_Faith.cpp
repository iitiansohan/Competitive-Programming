#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m);

    for (int i = 0; i < m; i++) 
        cin >> a[i];

    sort(a.begin(), a.end());

    int f = a[0];
    vector<int> b(a.begin() + 1, a.end());

    int pc = n, nc = n - 1;
    vector<int> p, q;

    int sz = b.size();

    for (int i = sz - pc; i < sz; i++) 
        p.push_back(b[i]);

    for (int i = 0; i < nc; i++) 
        q.push_back(b[i]);

    reverse(p.begin(), p.end());

    vector<int> s;
    int idx1 = 0, idx2 = 0;

    for (int i = 0; i < m - 1; i++) {
        if (i % 2 == 0) 
            s.push_back(p[idx1++]);
        else 
            s.push_back(q[idx2++]);
    }

    int sum = 0;

    for (int i = 0; i < m - 1; i++) {
        if (i % 2 == 0) 
            sum += s[i];
        else 
            sum -= s[i];
    }

    int sec = f + sum;
    vector<int> res = {f, sec};

    for (auto &v : s) 
        res.push_back(v);

    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << (i + 1 == res.size() ? "\n" : " ");
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
