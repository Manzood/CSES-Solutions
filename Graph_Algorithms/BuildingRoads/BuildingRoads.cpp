#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <vector <int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <bool> visited(n, false);
    auto dfs = [&] (auto& self, int node) -> void {
        visited[node] = true;
        for (auto u: adj[node]) {
            if (!visited[u]) self(self, u);
        }
    };
    dfs (dfs, 0);
    vector<vector <int>> roads;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs (dfs, i);
            roads.push_back({1, i + 1});
        }
    }
    printf("%lld\n", (int) roads.size());
    for (int i = 0; i < (int) roads.size(); i++) {
        printf("%lld %lld\n", roads[i][0], roads[i][1]);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
