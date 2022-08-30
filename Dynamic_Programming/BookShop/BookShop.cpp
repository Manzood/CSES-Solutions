#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

// dp[i][j] = maximum number of pages we can buy spending i money and j is the
// last book we will consider buying
// transitions: dp[i][j] = max(dp[i][j], dp[i - price[j]][j] + pages[j]);
// base state: dp[0] -> all values are zero
// final state: dp[x][n]

// I had to switch the values of i and j to try and get this code to pass, so
// the above transition is no longer valid without taking that into
// consideration

void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= x; i++) {
            // purchase the book, or don't purchase the book
            if (j - 1 >= 0) dp[j][i] = dp[j - 1][i];
            if (i - prices[j] >= 0) {
                if (j - 1 >= 0) {
                    dp[j][i] =
                        max(dp[j][i], dp[j - 1][i - prices[j]] + pages[j]);
                } else {
                    dp[j][i] = max(dp[j][i], pages[j]);
                }
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= x; j++) {
    //         printf("%lld ", dp[j][i]);
    //     }
    //     printf("\n");
    // }
    int ans = dp[n - 1][x];
    printf("%d\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
