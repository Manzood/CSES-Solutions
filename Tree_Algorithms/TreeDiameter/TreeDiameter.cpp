#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

pair<int, int> bfs(int node, vector<vector<int>>& adj) {
    queue<pair<int, int>> q;
    q.push({node, 0});
    int n = (int)adj.size();
    vector<bool> visited(n, false);
    visited[node] = true;
    pair<int, int> last;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        last = cur;
        q.pop();
        for (auto u : adj[cur.first]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push({u, cur.second + 1});
            }
        }
    }
    return last;
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
    pair<int, int> edgenode = bfs(0, adj);
    pair<int, int> othernode = bfs(edgenode.first, adj);
    printf("%lld\n", othernode.second);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
