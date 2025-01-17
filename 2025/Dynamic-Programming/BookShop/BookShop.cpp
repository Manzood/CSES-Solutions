#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &price[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pages[i]);
    }
    vector<vector<int>> dp(2, vector<int>(x + 1, 0));
    for (int j = price[0]; j <= x; j++) {
        dp[0][j] = pages[0];
    }
    for (int i = 1; i < n; i++) {
        dp[1].assign(x + 1, 0);
        for (int j = 1; j <= x; j++) {
            if (j >= price[i]) dp[1][j] += dp[0][j - price[i]] + pages[i];
            dp[1][j] = max(dp[1][j], dp[0][j]);
            dp[1][j] = max(dp[1][j], dp[1][j - 1]);
        }
        dp[0] = dp[1];
    }
    printf("%lld\n", dp[1][x]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
