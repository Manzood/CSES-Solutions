#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

vector<int> visited;

void dijkstra(vector<vector<pair<int, int>>>& adj, set<pair<int, int>>& s,
              vector<int>& d) {
    while (!s.empty()) {
        int node = s.begin()->second;
        int value = s.begin()->first;
        s.erase(s.begin());
        for (auto u : adj[node]) {
            // get the value for u
            int cur = d[u.first];
            if (s.find({cur, u.first}) != s.end()) {
                s.erase(s.find({cur, u.first}));
                cur = min(cur, value + u.second);
                s.insert({cur, u.first});
                d[u.first] = cur;
            }
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        adj[a - 1].push_back({b - 1, c});
    }
    visited.clear();
    visited.assign(n, false);
    vector<int> d(n, INF);
    d[0] = 0;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        s.insert({d[i], i});
    }
    dijkstra(adj, s, d);
    for (int i = 0; i < n; i++) {
        printf("%lld ", d[i]);
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
