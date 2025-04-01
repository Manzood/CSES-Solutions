#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

void solve([[maybe_unused]] int test) {
    int n, m, q;
    scanf("%lld%lld%lld", &n, &m, &q);
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        x--, y--;
        dist[x][y] = min(dist[x][y], z);
        dist[y][x] = min(dist[y][x], z);
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dist[j][i] = min(dist[j][i], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int query = 0; query < q; query++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x--, y--;
        printf("%lld\n", dist[x][y] == INF ? -1 : dist[x][y]);
    }
}

int32_t main() {
    int t = 1;
    /* cin >> t; */
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
