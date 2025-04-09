#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> player_decks(n);
    for (int i = 0; i < n; ++i) {
        player_decks[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> player_decks[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(player_decks[i].begin(), player_decks[i].end());
    }

    vector<pair<int, int>> min_cards;
    for (int i = 0; i < n; ++i) {
        min_cards.push_back({player_decks[i][0], i});
    }

    sort(min_cards.begin(), min_cards.end());

    vector<int> player_order;
    for (const auto& entry : min_cards) {
        player_order.push_back(entry.second + 1);
    }

    int current_top_card = -1;
    vector<vector<int>> remaining_decks = player_decks;

    for (int round = 0; round < m; ++round) {
        for (int player : player_order) {
            int player_idx = player - 1;
            if (!remaining_decks[player_idx].empty() && remaining_decks[player_idx][0] > current_top_card) {
                current_top_card = remaining_decks[player_idx][0];
                remaining_decks[player_idx].erase(remaining_decks[player_idx].begin());
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << player_order[i] << " ";
    }
    cout << endl;
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
