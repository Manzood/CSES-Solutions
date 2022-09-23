#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 1 x 2 tile
            if (j >= 2)
                dp[i][j] += dp[i - 1][j] + dp[i][j - 2] - dp[i - 1][j - 2];
            if (i >= 2)
                dp[i][j] += dp[i - 2][j] + dp[i][j - 1] - dp[i - 2][j - 1];
        }
    }
    printf("%lld\n", dp[n][m]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
