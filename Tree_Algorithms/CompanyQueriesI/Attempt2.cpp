#include "bits/stdc++.h"
using namespace std;
#define int long long

constexpr int LOG = 32;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector <int> par(n, -1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%lld", &par[i + 1]);
        par[i + 1]--;
    }
    vector <vector <int>> lift(n, vector <int> (LOG, -1));
    for (int i = 0; i < n; i++) lift[i][0] = par[i];
    for (int i = 0; i < n; i++) 
        for (int j = 1; j < LOG; j++) 
            if (lift[i][j - 1] != -1) lift[i][j] = lift[lift[i][j - 1]][j - 1];
    for (int query = 0; query < q; query++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        int cur = u;
        for (int i = 0; (1LL << i) <= v && cur != -1; i++) 
            if (v & (1LL << i)) 
                cur = lift[cur][i];
        printf("%lld\n", cur != -1 ? cur + 1 : cur);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}