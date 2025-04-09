#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const ld pie = 2 * acos(0);
const ld eps = 1e-6;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    vector<ld> res(t);
    
    for(int j = 0; j < t; j++) {
        int n, f;
        cin >> n >> f;
        f++;  // Adding the friends + 1 for total slices

        vector<int> r(n);
        for(int i = 0; i < n; i++)
            cin >> r[i];

        ld low = 0, high = pie * (*max_element(r.begin(), r.end())) * (*max_element(r.begin(), r.end()));
        int count = 0;
        
        while (high - low > eps && count <= 100) {
            ld mid = low + (high - low) / 2;
            int total_slices = 0;
            
            for(int i = 0; i < n; i++) {
                total_slices += (int)(pie * r[i] * r[i] / mid);
            }

            if (total_slices >= f) {
                low = mid;
            } else {
                high = mid;
            }
            count++;
        }
        res[j] = low;
    }

    for(int i = 0; i < t; i++)
        cout << fixed << setprecision(4) << res[i] << endl;

    return 0;
}
