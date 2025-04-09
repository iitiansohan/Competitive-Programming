//https://codeforces.com/problemset/problem/1119/B
#include <bits/stdc++.h>
#define int long long
using namespace std;

bool canPlaceBottles(vector<int>& bottles, int k, int h) {
    vector<int> selected(bottles.begin(), bottles.begin() + k);
    sort(selected.begin(), selected.end(), greater<int>());
    
    int totalHeight = 0;
    for (int i = 0; i < k; i += 2) {
        // Add the height of the taller bottle from every pair
        totalHeight += selected[i];
    }
    
    return totalHeight <= h;
}

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, h;
    cin >> n >> h;
    
    vector<int> bottles(n);
    for (int i = 0; i < n; i++) {
        cin >> bottles[i];
    }
    
    int left = 1, right = n, answer = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canPlaceBottles(bottles, mid, h)) {
            answer = mid;  // We can place `mid` bottles, try for more
            left = mid + 1;
        } else {
            right = mid - 1;  // We can't place `mid` bottles, try fewer
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
