#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        freq[x[i]]++;
    }

    int score = 0;
    for (auto &pair : freq) {
        int num=pair.first;
        int count=pair.second;
        int complement = k - num;
        if (freq.find(complement) != freq.end()) {
            if (num == complement) {
                score += freq[num] / 2;
                freq[num] = 0;
            } else {
                int pairs = min(freq[num], freq[complement]);
                score += pairs;
                freq[num] -= pairs;
                freq[complement] -= pairs;
            }
        }
    }

    cout << score << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
