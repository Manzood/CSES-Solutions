#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> price(n), a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            // dp[i][j] = maximum number of pages possible considering first i
            // books upto price j
            if (i == 0) {
                if (j >= price[i]) {
                    dp[i][j] = a[i];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                if (j >= price[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + a[i]);
                }
            }
        }
    }
    // for (int j = 1; j <= x; j++) {
    //     for (int i = 0; i < n; i ++) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n", dp[n - 1][x]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
