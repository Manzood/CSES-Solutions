#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.begin(), a.end());
    int sum = 0;
    int ans = 1e18;
    for (int i = 0; i < n; i++) {
        if (sum < a[i] - 1) {
            ans = min(ans, sum + 1);
        }
        sum += a[i];
    }
    ans = min(ans, sum + 1);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
