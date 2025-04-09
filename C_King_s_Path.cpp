#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

bool issafe(int i, int j, set<pair<int, int>> &st) {
    return (i >= 1 && j >= 1 && i <= 1e9 && j <= 1e9) && (st.find({i, j}) != st.end());
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    int n;
    cin >> n;
    set<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++) {
            st.insert({r, j});
        }
    }

    queue<pair<int, int>> q;
    q.push({x0, y0});
    
    map<pair<int, int>, int> dist;
    dist[{x0, y0}] = 0;
    
    int dx[] = {-1, 1, -1, 1, 0, 0, -1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, 1, -1};

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int x = u.first, y = u.second;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (!dist.count({nx, ny}) && issafe(nx, ny, st)) {
                q.push({nx, ny});
                dist[{nx, ny}] = dist[{x, y}] + 1;
            }
        }
    }

    if (dist.count({x1, y1})) {
        cout << dist[{x1, y1}] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
