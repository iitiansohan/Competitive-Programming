#include <bits/stdc++.h>
using namespace std;

void solve() {
    int len;
    cin >> len;

    vector<int> vecc(len);
    for (int i = 0; i < len; ++i) {
        cin >> vecc[i];
    }

    bool isValid = true;

    for (int i = 0; i < len; ++i) {
        int l = i;
        int r = len - i - 1;
        int required = 2 * max(l, r) + 1;

        if (vecc[i] < required) {
            cout << "NO\n";
            isValid = false;
            break;
        }
    }

    if (isValid) {
        cout << "YES\n";
    }
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
