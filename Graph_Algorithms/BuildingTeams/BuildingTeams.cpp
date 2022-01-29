#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector <int> assignment;
vector <bool> visited;
bool possible = true;
void dfs (int node, vector <vector<int>>& adj, int team) {
    if (visited[node]) return;
    assignment[node] = team;
    visited[node] = true;
    for (auto u: adj[node]) {
        if (assignment[u] == team) possible = false;
        assignment[u] = (team % 2) + 1;
        dfs (u, adj, assignment[u]);
    }
}

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <vector <int>> adj(n);
    assignment.resize(n, -1);
    visited.resize(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // it's a dfs
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, adj, 1);
    }
    if (possible) {
        for (int i = 0; i < n; i++) {
            printf("%lld ", assignment[i]);
        }
        printf("\n");
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
