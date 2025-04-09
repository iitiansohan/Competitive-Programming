#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <iostream>
using namespace std;

#define LL long long
#define MAXN 200005
#define LOG 21

int parent[MAXN], rnk[MAXN];

void make_set(int n) {
    int i;
    for(i = 1; i <= n; i++) {
        parent[i] = i;
        rnk[i] = 1;
    }
}

int find_set(int v) {
    if (parent[v] == v) return v;
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(rnk[a] > rnk[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[a] = b;
        if(rnk[a] == rnk[b]) {
            rnk[b]++;
        }
    }
}

typedef pair< int, pair<int, int> > Edge;

// Global arrays for LCA: up[v][i] is 2^i-th ancestor of v,
// and maxEdge[v][i] is the maximum edge weight on the path from v to up[v][i].
int up[MAXN][LOG];
int maxEdge[MAXN][LOG];
int depth[MAXN];

// Adjacency list for the MST tree: (neighbor, weight)
vector< pair<int, int> > adj[MAXN];

// DFS to initialize depth, up[][0] and maxEdge[][0]
void dfs(int v, int p, int w) {
    int i;
    up[v][0] = p;
    maxEdge[v][0] = w; // edge weight from v to p (0 for root)
    for(i = 1; i < LOG; i++) {
        up[v][i] = up[ up[v][i-1] ][i-1];
        maxEdge[v][i] = max( maxEdge[v][i-1], maxEdge[ up[v][i-1] ][i-1] );
    }
    for (size_t i2 = 0; i2 < adj[v].size(); i2++) {
        int nxt = adj[v][i2].first;
        int wght = adj[v][i2].second;
        if(nxt == p) continue;
        depth[nxt] = depth[v] + 1;
        dfs(nxt, v, wght);
    }
}

// Function to get the maximum edge weight in the path from u to v in the MST.
int get_max_edge(int u, int v) {
    int i, maxW = 0;
    if(depth[u] < depth[v]) {
        int temp = u;
        u = v;
        v = temp;
    }
    // Bring u up to the same depth as v.
    for(i = LOG-1; i >= 0; i--) {
        if(depth[u] - (1 << i) >= depth[v]) {
            if(maxEdge[u][i] > maxW)
                maxW = maxEdge[u][i];
            u = up[u][i];
        }
    }
    if(u == v)
        return maxW;
    // Bring both u and v up until their ancestors match.
    for(i = LOG-1; i >= 0; i--) {
        if(up[u][i] != up[v][i]) {
            if(maxEdge[u][i] > maxW)
                maxW = maxEdge[u][i];
            if(maxEdge[v][i] > maxW)
                maxW = maxEdge[v][i];
            u = up[u][i];
            v = up[v][i];
        }
    }
    // Last step: compare the direct edges from u and v to their parent (which is LCA)
    if(maxEdge[u][0] > maxW)
        maxW = maxEdge[u][0];
    if(maxEdge[v][0] > maxW)
        maxW = maxEdge[v][0];
    return maxW;
}

int main() {
    // Use stdio for faster I/O in older compilers
    int N, M, Q, i;
    scanf("%d %d %d", &N, &M, &Q);
    
    vector<Edge> edges;
    edges.resize(M);
    for(i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        // Store as (weight, (u, v))
        edges[i] = make_pair(c, make_pair(a, b));
    }
    
    // Build MST using Kruskal's algorithm.
    sort(edges.begin(), edges.end());
    make_set(N);
    
    // We'll build the MST tree by adding edges that join different components.
    for(i = 0; i < M; i++) {
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(find_set(a) != find_set(b)) {
            union_sets(a, b);
            // Add undirected edge in the MST
            adj[a].push_back(make_pair(b, w));
            adj[b].push_back(make_pair(a, w));
        }
    }
    
    // Precompute LCA information. We can choose any node as root; here we use 1.
    depth[1] = 0;
    dfs(1, 1, 0);
    
    // Process each query.
    for(i = 0; i < Q; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // The maximum edge in the path from u to v in the MST
        int maxInPath = get_max_edge(u, v);
        // If the new edge's weight is less than the maximum weight edge,
        // then adding it would replace that edge in the MST.
        if(w < maxInPath)
            printf("Yes\n");
        else
            printf("No\n");
    }
    
    return 0;
}
