#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int LOG = 20;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> p(n, -1);
    vector<vector<int>> lift(n, vector<int>(LOG, -1));
    vector<int> depth(n, 0);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &p[i]);
        p[i]--;
        if (p[i] != -1) depth[i] = depth[p[i]] + 1;
        lift[i][0] = p[i];
    }
    for (int exp = 1; exp < LOG; exp++) {
        for (int i = 0; i < n; i++) {
            if (lift[i][exp - 1] != -1)
                lift[i][exp] = lift[lift[i][exp - 1]][exp - 1];
        }
    }
    for (int query = 0; query < q; query++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        a--;
        b--;
        if (depth[b] > depth[a]) swap(a, b);
        int val = depth[a] - depth[b];
        int cur = a;
        for (int i = 0; i < LOG && cur != -1; i++) {
            if ((1LL << i) & val) {
                if (cur != -1) cur = lift[cur][i];
            }
        }
        // assert(depth[cur] == depth[b]);
        int ans = -1;
        if (cur == b) {
            ans = b;
        } else {
            int other = b;
            for (int i = LOG - 1; i >= 0; i--) {
                if (lift[cur][i] != lift[other][i]) {
                    cur = lift[cur][i];
                    other = lift[other][i];
                } else {
                    ans = lift[cur][i];
                }
            }
        }
        printf("%lld\n", ans + 1);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
