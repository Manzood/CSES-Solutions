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
    string s, t;
    cin >> s >> t;
    n = (int)s.size(), m = (int)t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0 && j > 0 && s[i - 1] != t[j - 1])
                dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
            else if (i > 0 && j > 0)
                dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);

            if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);

            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
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
