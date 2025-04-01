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
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &a[i][1], &a[i][0], &a[i][2]);
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = a[i][0];
    vector<int> dp(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = a[i][2];
        if (i > 0) {
            int ind = lower_bound(b.begin(), b.end(), a[i][1]) - b.begin();
            ind--;
            if (ind >= 0) {
                dp[i] = max(dp[i], a[i][2] + dp[ind]);
            }
            dp[i] = max(dp[i], dp[i - 1]);
        }
        ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    /* cin >> t; */
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
