#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    // dp[i][j] = minimum number of moves to cut a rectangle of dimensions
    // (i x j) into squares
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                for (int k = 1; k < min(i, j); k++) {
                    dp[i][j] = min(dp[i][j], 2 + dp[i - k][k] + dp[i][j - k]);
                    dp[i][j] = min(dp[i][j], 2 + dp[k][j - k] + dp[i - k][j]);
                }
                int k = min(i, j);
                dp[i][j] = min(dp[i][j], 1 + dp[i - k][k] + dp[k][j - k]);
            }
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
