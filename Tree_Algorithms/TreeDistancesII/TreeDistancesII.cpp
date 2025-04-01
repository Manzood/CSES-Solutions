#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> subtree(n, 1);
    function<int(int, int)> calc = [&](int node, int par) {
        int ret = 0;
        for (auto u : adj[node]) {
            if (u == par) continue;
            ret += calc(u, node);
            ret += subtree[u];
            subtree[node] += subtree[u];
        }
        return ret;
    };
    vector<int> ans(n, 0);
    ans[0] = calc(0, -1);
    function<void(int, int, int)> fin = [&](int node, int par, int add) {
        ans[node] = add - subtree[node] + ans[par];
        for (auto u : adj[node]) {
            if (u == par) continue;
            add += subtree[u];
        }
        add++;
        for (auto u : adj[node]) {
            if (u == par) continue;
            fin(u, node, add - subtree[u]);
        }
    };
    for (auto u : adj[0]) fin(u, 0, subtree[0] - subtree[u]);
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    /* cin >> t; */
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
