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
    vector<int> res(t);

    for (int j = 0; j < t; j++) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];  // positive integers
        }

        // Sort in descending order
        sort(arr.begin(), arr.end(), greater<int>());

        int high = n - 1;

        // Merge adjacent elements as per the logic
        while (high > 0) {
            int a = arr[high], b = arr[high - 1];
            high--;
            arr[high] = floor((a + b) / 2);  // Merge step
        }

        // Store the result for this test case
        res[j] = arr[0];
    }

    // Output results for all test cases
    for (int i = 0; i < t; i++) {
        cout << res[i] << endl;
    }

    return 0;
}
