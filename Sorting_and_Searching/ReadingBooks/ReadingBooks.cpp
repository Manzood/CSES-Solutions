#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - 1) s1 += a[i];
        if (i > 0) s2 += a[i];
    }
    int t1 = s1 > a[n - 1] ? s1 + a[n - 1] : 2 * a[n - 1];
    int t2 = s2 > a[0] ? s2 + a[0] : 2 * a[0];
    int ans = max(t1, t2);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
