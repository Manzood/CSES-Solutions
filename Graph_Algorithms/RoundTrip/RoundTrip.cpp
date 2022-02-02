#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector <bool> visited;
vector <bool> visiting;
vector <int> p;
bool possible = false;
int source = -1;
void dfs (int node, vector <vector <int>>& adj, int parent) {
    if (visited[node]) return;
    if (possible) return;
    // debug (node + 1);
    p[node] = parent;
    // debug (node + 1, p[node] + 1);
    visited[node] = true;
    visiting[node] = true;
    for (auto u: adj[node]) {
        if (visiting[u] && u != parent) {
            // debug (u + 1);
            possible = true;
            source = u;
            p[u] = node;
            return;
        }
        dfs(u, adj, node);
        if (possible) return;
    }
    visiting[node] = false;
}

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <vector <int>> adj(n);
    visited.resize(n, false);
    visiting.resize(n, false);
    p.resize(n, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        dfs (i, adj, -1);
    }
    if (possible) {
        vector <int> path;
        int node = source;
        // debug (p);
        // debug (node + 1, p[node] + 1);
        while (p[node] != source) {
            path.push_back(node);
            node = p[node];
            // debug (node + 1, p[node] + 1);
        }
        path.push_back(node);
        path.push_back(source);
        printf("%lld\n", (int) path.size());
        for (int i = 0; i < (int) path.size(); i++) printf("%lld%c", path[i] + 1, " \n"[i == (int) path.size() - 1]);
    } else {
        printf("IMPOSSIBLE\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
