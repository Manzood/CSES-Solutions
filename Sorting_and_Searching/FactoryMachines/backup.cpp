#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, t;
    scanf("%lld%lld", &n, &t);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    debug(a);
    int ans = (int)1e9 + 7;
    float inv = 0.0f;
    for (int i = 0; i < n; i++) {
        int cnt = (int)(inv * a[i]) + 1;
        debug(cnt);
        if (cnt >= t) {
            ans = min(ans, a[i]);
        }
        inv += (float)1.0f / a[i];
        int fin = ((t + cnt - 1) / cnt) * a[i];
        ans = min(ans, fin);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
