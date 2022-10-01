#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int inf = (int)1e18;

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void dijkstra(vector<vector<vector<int>>>& adj) {
    int n = adj.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
        min_pq;
    min_pq.push({0, 0});
    for (int i = 1; i < n; i++) {
        min_pq.push({inf, i});
    }
    while (!min_pq.empty()) {
        vector<int> cur = min_pq.top();
        int node = cur[1];
        int dist = cur[0];
        for (auto& u : adj[node]) {
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<vector<int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
