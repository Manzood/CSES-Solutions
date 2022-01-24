#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int INF = (int) 1e9 + 7;

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <vector <int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        a--; b--;
        adj[a].push_back (b);
        adj[b].push_back (a);
    }
    queue <int> q;
    q.push(0);
    vector <int> dist(n, INF);
    vector <bool> visited(n, false);
    vector <int> prev(n, -1);
    dist[0] = 0;
    visited[0] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto u: adj[node]) {
            if (!visited[u]) {
                visited[u] = true;
                dist[u] = dist[node] + 1;
                prev[u] = node;
                q.push(u);
            }
        }
    }
    vector <int> path;
    path.push_back(n);
    while (prev[path.back() - 1] != -1) {
        path.push_back (prev[path.back() - 1] + 1);
    }
    reverse(path.begin(), path.end());
    if (dist[n-1] < INF) {
        printf("%lld\n", (int) path.size());
        for (int i = 0; i < (int) path.size(); i++) {
            printf("%lld ", path[i]);
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
