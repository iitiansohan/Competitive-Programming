#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);  // We use 1-based indexing for convenience

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int current_len = n;  // Start with the initial length of the array
        int i = 2;  // Start from the second element

        // Keep checking until i exceeds the current length dynamically
        while (i <= current_len) {
            if (a[i] == current_len + 1 - i) {
                current_len += (i - 1);  // Increase the array length by appending i-1 zeros
            }
            i++;
        }

        cout << current_len << endl;
    }
}

int main() {
    solve();
    return 0;
}
