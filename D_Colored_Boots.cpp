#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;

    vector<int> left[26], right[26];
    vector<int> left_q, right_q;

    for (int i = 0; i < n; i++) {
        if (l[i] == '?') left_q.push_back(i);
        else left[l[i] - 'a'].push_back(i);
        
        if (r[i] == '?') right_q.push_back(i);
        else right[r[i] - 'a'].push_back(i);
    }

    vector<pair<int, int>> pairs;

    
    for (int c = 0; c < 26; c++) {
        while (!left[c].empty() && !right[c].empty()) {
            pairs.push_back({left[c].back() + 1, right[c].back() + 1});
            left[c].pop_back();
            right[c].pop_back();
        }
    }

    
    for (int c = 0; c < 26; c++) {
        while (!left_q.empty() && !right[c].empty()) {
            pairs.push_back({left_q.back() + 1, right[c].back() + 1});
            left_q.pop_back();
            right[c].pop_back();
        }
    }

    
    for (int c = 0; c < 26; c++) {
        while (!right_q.empty() && !left[c].empty()) {
            pairs.push_back({left[c].back() + 1, right_q.back() + 1});
            left[c].pop_back();
            right_q.pop_back();
        }
    }

    
    while (!left_q.empty() && !right_q.empty()) {
        pairs.push_back({left_q.back() + 1, right_q.back() + 1});
        left_q.pop_back();
        right_q.pop_back();
    }

    
    cout << pairs.size() << endl;
    for (auto& p : pairs) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
