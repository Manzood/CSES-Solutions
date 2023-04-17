#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int get_subtree(int node, int par, vector<vector<int>>& adj,
                vector<int>& subtree) {
    if (subtree[node] > -1) return subtree[node];
    subtree[node] = 1;
    for (auto u : adj[node]) {
        if (u == par) continue;
        subtree[node] += get_subtree(u, node, adj, subtree);
    }
    return subtree[node];
}

int find_centroid(int node, vector<vector<int>>& adj, vector<int>& subtree) {
    int root = node;
    int mx = 0;
    int mx_node = -1;
    for (auto u : adj[node]) {
        int val = get_subtree(u, node, adj, subtree);
        if (val > mx) {
            mx = val;
            mx_node = u;
        }
    }
    if (mx > (int)adj.size() / 2) {
        subtree[node] = 1;
        for (auto u : adj[node]) {
            if (u == mx_node) continue;
            subtree[node] += subtree[u];
        }
        root = find_centroid(mx_node, adj, subtree);
    }
    return root;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> subtree(n, -1);
    get_subtree(0, -1, adj, subtree);
    int root = find_centroid(0, adj, subtree);
    printf("%lld\n", root + 1);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
