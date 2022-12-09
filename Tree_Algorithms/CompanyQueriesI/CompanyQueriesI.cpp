#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int LOG = 32;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> p(n, -1);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &p[i]);
        p[i]--;
    }
    vector<vector<int>> lift(n, vector<int>(LOG, -1));
    for (int i = 0; i < n; i++) {
        lift[i][0] = p[i];
    }
    for (int exp = 1; exp < LOG; exp++) {
        for (int i = 0; i < n; i++) {
            if (lift[i][exp - 1] != -1)
                lift[i][exp] = lift[lift[i][exp - 1]][exp - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        int x, k;
        scanf("%lld%lld", &x, &k);
        x--;
        int par = x;
        for (int j = 0; j < LOG && par != -1; j++) {
            if ((1LL << j) & k) {
                par = lift[par][j];
            }
        }
        printf("%lld\n", par == -1 ? par : par + 1);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
