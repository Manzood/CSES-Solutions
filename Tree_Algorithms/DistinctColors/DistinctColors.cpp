#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

map<int, int> cnt;
vector<bool> visited;

int dfs(int node, vector<vector<int>>& adj, vector<int>& ans,
        vector<int>& color) {
    if (visited[node]) return 0;
    int retval = 0;
    visited[node] = true;
    for (auto u : adj[node]) {
        retval += dfs(u, adj, ans, color);
    }
    if (cnt.count(color[node]) == 0) {
        retval++;
        cnt[color[node]]++;
    }
    debug(node);
    return ans[node] = retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> color(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &color[i]);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited.assign(n, false);
    vector<int> ans(n, 0);
    dfs(0, adj, ans, color);
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
