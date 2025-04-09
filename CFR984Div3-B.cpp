#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;

        // Vector of vectors to store costs by brand index (1-based indexing)
        vector<vector<int>> brand_costs(k + 1);

        // Read bottle information and store costs in brand_costs vector
        for (int i = 0; i < k; i++) {
            int b, c;
            cin >> b >> c;
            brand_costs[b].push_back(c);
        }

        // Prepare a list to store the maximum sum per brand
        vector<long long> brand_sums;

        for (int i = 1; i <= k; i++) {  // Iterate over each brand
            if (!brand_costs[i].empty()) {
                vector<int>& costs = brand_costs[i];
                sort(costs.rbegin(), costs.rend()); // Sort descending
                
                long long brand_sum = 0;
                for (int cost : costs) {
                    brand_sum += cost;
                }
                brand_sums.push_back(brand_sum); // Total value for this brand
            }
        }

        // Sort all brand sums in descending order to maximize the total sum
        sort(brand_sums.rbegin(), brand_sums.rend());

        // Sum the highest possible values based on the number of shelves, n
        long long max_earnings = 0;
        for (int i = 0; i < min(n, (int)brand_sums.size()); i++) {
            max_earnings += brand_sums[i];
        }

        cout << max_earnings << "\n";
    }

    return 0;
}
