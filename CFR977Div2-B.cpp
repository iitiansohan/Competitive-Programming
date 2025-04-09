#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());  // Sort the array
        
        set<int> present;
        for (int i = 0; i < n; i++) {
            present.insert(a[i]);  // Track the elements present in the array
        }
        
        int current_mex = 0;  // Start with the smallest possible MEX (0)
        int extra_operations = 0;  // Count how many multiples of x we can use
        
        for (int i = 0; i < n; i++) {
            if (a[i] == current_mex) {
                current_mex++;  // Increment MEX if it's already present
            } else if (a[i] > current_mex) {
                // We have a gap; try to fill it using the x operation
                if (extra_operations > 0) {
                    extra_operations--;
                    current_mex++;
                } else {
                    break;  // Can't fill the gap, stop the loop
                }
            }
        }
        
        // After checking for gaps, continue adding multiples of x if possible
        current_mex += extra_operations;
        
        cout << current_mex << endl;  // Output the maximum possible MEX
    }

    return 0;
}
