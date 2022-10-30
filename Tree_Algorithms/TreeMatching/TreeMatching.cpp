#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<bool> visited;
pair<int, int> dfs(int node, vector<vector<int>>& adj) {
    pair<int, int> retval = {0, 0};
    if (visited[node]) return retval;
    visited[node] = true;
    retval.first = 1;
    if (node == 0) retval.first = 0;
    // note: also consider not selecting any child node even if current node
    // hasn't been selected
    vector<pair<int, int>> t;
    int sum = 0;
    for (auto u : adj[node]) {
        t.push_back(dfs(u, adj));
        retval.first += t.back().second;
        sum += t.back().second;
    }
    retval.second = sum;
    for (auto x : t) {
        retval.second = max(retval.second, sum - x.second + x.first);
    }
    return retval;
}

// easy dp solution

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
    visited.assign(n, false);
    pair<int, int> t = dfs(0, adj);
    int ans = max(t.first, t.second);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
