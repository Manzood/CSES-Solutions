#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

vector <bool> visited;
vector <int> ans;
int dfs (int node, vector <vector <int>>& adj) {
    if (visited[node]) return 0;
    visited[node] = true;
    int retval = 1;
    for (auto u: adj[node]) {
        retval += dfs (u, adj);
    }
    ans[node] = retval;
    return retval;
}

void solve() {
    int n;
    scanf("%lld", &n);
    vector <vector <int>> adj(n);
    visited.resize(n, false);
    ans.resize (n, 0);
    for (int i = 1; i < n; i++) {
        int v;
        scanf("%lld", &v);
        v--;
        adj[v].push_back (i);
    }
    dfs(0, adj);
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i] - 1);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
