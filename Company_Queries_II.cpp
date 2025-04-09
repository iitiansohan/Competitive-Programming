#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int up[N][20];
void dfs(int &count, int u, int p, vector<vector<int>> &adj, vector<int> &in, vector<int> &out) {
    in[u] = ++count;
    up[u][0] = p;
    for (int i = 1; i < 20; i++) {
        int halfpar = up[u][i - 1];
        up[u][i] = (halfpar == -1) ? -1 : up[halfpar][i - 1];
    }
    for (auto ch : adj[u]) {
        if (ch == p) continue;
        dfs(count, ch, u, adj, in, out);
    }
    out[u] = ++count;
}
bool isans(int u, int v, vector<int> &in, vector<int> &out) {
    return in[u] <= in[v] && out[u] >= out[v];
}
int lca(int u, int v, vector<int> &in, vector<int> &out) {
    if (isans(u, v, in, out)) return u;
    if (isans(v, u, in, out)) return v;

    for (int i = 19; i >= 0; i--) {
        if (up[u][i] != -1 && !isans(up[u][i], v, in, out)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);

    for (int i = 2; i <= n; i++) {
        int e;
        cin >> e;
        adj[i].push_back(e);
        adj[e].push_back(i);
    }
    vector<int> in(n + 1), out(n + 1);
    int count = 0;
    dfs(count, 1, -1, adj, in, out);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b, in, out) << endl;
    }
    return 0;
}
