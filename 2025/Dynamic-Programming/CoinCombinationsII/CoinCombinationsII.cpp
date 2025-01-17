#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < x + 1; j++) {
            int c = coins[i];
            if (i > 0) dp[i][j] = dp[i - 1][j];
            if (j - c >= 0) (dp[i][j] += dp[i][j - c]) %= INF;
        }
    }
    printf("%d\n", dp[n - 1][x]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
