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
    vector<bool> present(n + 1, false);
    vector<bool> found(n + 1, false);
    for (int i = 0; i < n; i++) {
        if (found[a[i] - 1]) present[a[i]] = true;
        found[a[i]] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!present[i]) ans++;
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
