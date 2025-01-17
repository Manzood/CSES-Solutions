#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n), pref(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pref[i] = a[i] + ((i > 0) ? pref[i - 1] : 0LL);
    }
    for (int query = 0; query < q; query++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x--, y--;
        printf("%lld\n", pref[y] - (x > 0 ? pref[x - 1] : 0LL));
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
