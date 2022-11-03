#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> visited, val;

int dfs1(int node, vector<vector<int>>& adj) {
    visited[node] = true;
    vector<int> t;
    int mx = 0, mx2 = 0;
    for (auto u : adj[node]) {
        if (!visited[u]) {
            int cur = dfs1(u, adj) + 1;
            if (node == 0) t.push_back(cur);
            if (mx <= cur) {
                mx2 = mx;
                mx = cur;
            }
        }
    }
    for (auto x : t) {
        if (x == mx) {
            val.push_back(mx2);
        } else {
            val.push_back(mx);
        }
    }
    return mx;
}

int dfs2(int node, vector<vector<int>>& adj, int mx, vector<int>& ans,
         int depth) {
    if (visited[node]) return 0;
    int retval = 0;
    visited[node] = true;
    ans[node] = depth + mx;
    for (auto x : adj[node]) {
        int cur = dfs2(x, adj, mx, ans, depth + 1);
        retval = max(retval, cur + 1);
    }
    ans[node] = max(ans[node], retval);
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans(n, 0);
    visited.assign(n, false);
    ans[0] = dfs1(0, adj);
    debug(ans, val);
    for (int i = 0; i < (int)adj[0].size(); i++) {
        visited.assign(n, false);
        visited[0] = true;
        dfs2(adj[0][i], adj, val[i], ans, 1);
    }
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
