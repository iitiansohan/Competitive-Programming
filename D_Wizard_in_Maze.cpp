#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

bool isvalid(int x, int y, int h, int w) {
    return (x >= 0) && (x < h) && (y >= 0) && (y < w);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    ch--; cw--; dh--; dw--;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    vector<vector<int>> dist(h, vector<int>(w, inf));
    deque<pair<int, int>> dq;
    dq.push_back({ch, cw});
    dist[ch][cw] = 0;
    while (!dq.empty()) {
        int x=dq.front().first;
        int y=dq.front().second;
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isvalid(nx, ny, h, w) && grid[nx][ny] == '.' && dist[nx][ny] > dist[x][y]) {
                dist[nx][ny] = dist[x][y];
                dq.push_front({nx, ny});
            }
        }
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int nx = x + i;
                int ny = y + j;

                if (isvalid(nx, ny, h, w) && grid[nx][ny] == '.' && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back({nx, ny});
                }
            }
        }
    }
    cout << (dist[dh][dw] == inf ? -1 : dist[dh][dw]) << endl;
    return 0;
}
