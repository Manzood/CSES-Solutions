#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> visited;

pair<int, int> bfs(int node, vector<vector<int>>& adj) {
    queue<pair<int, int>> q;
    int n = (int)adj.size();
    visited.assign(n, false);
    q.push({node, 0});
    visited[node] = true;
    pair<int, int> last;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        last = q.front();
        q.pop();
        // debug(last);
        for (auto u : adj[cur.first]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push({u, cur.second + 1});
            }
        }
    }
    return last;
}

void getdist(int node, vector<vector<int>>& adj, vector<int>& dist, int depth) {
    if (visited[node]) return;
    visited[node] = true;
    dist[node] = depth;
    for (auto u : adj[node]) {
        getdist(u, adj, dist, depth + 1);
    }
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
    pair<int, int> firstedge = bfs(0, adj);
    pair<int, int> secondedge = bfs(firstedge.first, adj);
    // find the distance from each node to either of the edges, i.e. the
    // distance from each of the edges to each node
    vector<int> dist1(n, 0), dist2(n, 0);
    visited.assign(n, false);
    getdist(firstedge.first, adj, dist1, 0);
    visited.assign(n, false);
    getdist(secondedge.first, adj, dist2, 0);
    // debug(dist1, dist2);
    for (int i = 0; i < n; i++) {
        printf("%lld ", max(dist1[i], dist2[i]));
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
