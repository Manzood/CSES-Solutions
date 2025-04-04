#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    if (a[0] == 0) {
        for (int i = 1; i <= m; i++) dp[0][i] = 1;
    } else {
        dp[0][a[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] > 0) {
            dp[i][a[i]] = (((dp[i - 1][a[i] - 1] + dp[i - 1][a[i]]) % MOD) +
                           dp[i - 1][a[i] + 1]) %
                          MOD;
        } else {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (((dp[i - 1][j - 1] + dp[i - 1][j]) % MOD) +
                            dp[i - 1][j + 1]) %
                           MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) (ans += dp[n - 1][i]) %= MOD;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
