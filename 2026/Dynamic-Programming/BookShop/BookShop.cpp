#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    vector<int> best(x + 1);
    for (int i = 0; i < n; i++) {
        vector<int> cpy = best;
        for (int j = a[i]; j <= x; j++) {
            cpy[j] = max(cpy[j], best[j - a[i]] + b[i]);
        }
        best = cpy;
    }

    printf("%lld\n", best[x]);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
