#include "bits/stdc++.h"
#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
const int mod = (int)1e9 + 7;

// This does not get accepted, unfortunately. This file was useful for testing
// #pragmas. They do not make a significant difference.
// even using an array instead of a vector did not solve the problem (though it
// did make a somewhat significant difference)

int32_t main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins.begin(), coins.end());
    int dp[x + 1][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) dp[i][j] += dp[i][j - 1];
            if (i - coins[j] >= 0) dp[i][j] += dp[i - coins[j]][j];
            dp[i][j] %= mod;
        }
    }
    printf("%d\n", dp[x][n - 1]);
}
