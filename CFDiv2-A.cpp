#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int res[t]{};

    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> x(n);

        // Reading the constraints
        for(int j = 0; j < n; j++) {
            cin >> a[j] >> x[j];
        }

        int low = -1e9, high = 1e9;  // Updated bounds for the valid range of k
        int count = 0;  // To count exclusions from type 3 constraints

        // Process type 1 and type 2 constraints first
        for(int j = 0; j < n; j++) {
            if (a[j] == 1) {
                // k >= x[j] -> Update the lower bound
                low = max(low, x[j]);
            }
            if (a[j] == 2) {
                // k <= x[j] -> Update the upper bound
                high = min(high, x[j]);
            } 
        }

        // Now process type 3 constraints
        for(int j = 0; j < n; j++) {
            if (a[j] == 3) {
                // Check if k == x[j] is in the valid range [low, high]
                if (x[j] >= low && x[j] <= high) {
                    count++;  // Exclude this value from the valid range
                }
            }
        }

        // Calculate result for this test case
        if (low > high) {
            res[i] = 0;  // No valid values if bounds are inconsistent
        } else {
            res[i] = (high - low + 1) - count;  // Valid range minus exclusions
        }
    }

    // Output results for all test cases
    for (int i = 0; i < t; i++) {
        cout << res[i] << endl;
    }

    return 0;
}
