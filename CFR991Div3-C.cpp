#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int c2 = 0, c3 = 0, sum = 0;
    for (char ch : s) {
        sum += ch - '0';
        if (ch == '2') ++c2;
        else if (ch == '3') ++c3;
    }

    int rem = sum % 9;
    int lookup[]{ 0, 8, 16, 6, 14, 4, 12, 2, 10 };
    int req = lookup[rem];
    
    while (req > 0) {
        if (c3 > 0 && req >= 6) {
            req -= 6;
            --c3;
        } else if (c2 > 0 && req >= 2) {
            req -= 2;
            --c2;
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
