#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int val = 1;
    int ans = (int) 1e18;
    while (val < (1LL << (n + 1))) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++) {
            if ((1LL << j) & val) {
                sum1 += a[j];
            } else {
                sum2 += a[j];
            }
        }
        ans = min (ans, abs (sum1 - sum2));
        val++;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
