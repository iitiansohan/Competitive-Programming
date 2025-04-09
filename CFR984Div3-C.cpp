#include <bits/stdc++.h>
using namespace std;

bool check1100(const string &s, int pos) {
    // Check if "1100" exists starting at `pos` in the string
    return pos >= 0 && pos + 3 < s.size() && s[pos] == '1' && s[pos + 1] == '1' && s[pos + 2] == '0' && s[pos + 3] == '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int q;
        cin >> q;

        set<int> found_1100;

        // Preprocess to find all initial positions of "1100"
        for (int i = 0; i <= n - 4; i++) {
            if (check1100(s, i)) {
                found_1100.insert(i);
            }
        }

        // Process each query
        while (q--) {
            int i, v;
            cin >> i >> v;
            --i;  // Convert to 0-based index

            // Remove "1100" patterns around the affected area before updating
            for (int j = i - 3; j <= i; j++) {
                if (check1100(s, j)) {
                    found_1100.erase(j);
                }
            }

            // Update the string
            s[i] = '0' + v;

            // Recheck for "1100" patterns around the affected area after updating
            for (int j = i - 3; j <= i; j++) {
                if (check1100(s, j)) {
                    found_1100.insert(j);
                }
            }

            // Output result based on the presence of "1100"
            cout << (found_1100.empty() ? "NO" : "YES") << "\n";
        }
    }

    return 0;
}
