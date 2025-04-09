#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isValid(const vector<int>& arr, int n, int d, double x, pair<int, int>& result) {
    vector<double> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + (arr[i - 1] - x);
    }

    double minPrefix = 0;
    int start = 0;
    for (int i = d; i <= n; ++i) {
        if (prefixSum[i] - minPrefix >= 0) {
            result = {start + 1, i};
            return true;
        }
        if (prefixSum[i - d + 1] < minPrefix) {
            minPrefix = prefixSum[i - d + 1];
            start = i - d + 1;
        }
    }
    return false;
}
void findMaxMeanSegment(int n, int d, const vector<int>& arr) {
    double l = 0, r = 100, bestMean = 0;
    pair<int, int> bestSegment = {1, d};

    for (int iter = 0; iter < 100; ++iter) { 
        double mid = (l + r) / 2;
        pair<int, int> currentSegment;

        if (isValid(arr, n, d, mid, currentSegment)) {
            bestMean = mid;
            bestSegment = currentSegment;
            l = mid+1; 
        } else {
            r = mid-1; 
        }
    }
    cout << bestSegment.first << " " << bestSegment.second << endl;
}
int32_t main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    findMaxMeanSegment(n, d, arr);
    return 0;
}
