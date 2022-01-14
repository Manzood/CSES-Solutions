#include "bits/stdc++.h"
#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
const int mod = (int)1e9 + 7;

// notes: if you take the following code, it does not work

/* vector<vector<int>> dp(x + 1, vector<int>(n, 0));
dp[0][0] = 1;
for (int i = 0; i <= x; i++) {
    for (int j = 0; j < n; j++) {
        if (j > 0) dp[i][j] += dp[i][j - 1];
        if (i - coins[j] >= 0) dp[i][j] += dp[i - coins[j]][j];
        dp[i][j] %= mod;
    }
} */

// this is because for some reason, it is twice as slow
// simply interchanging what i and j is enough to get an accepted value, as the
// bounds for this problem are incredibly tight

int32_t main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j >= coins[i]) dp[i][j] += dp[i][j - coins[i]];
            dp[i][j] %= mod;
        }
    }
    printf("%d\n", dp[n - 1][x]);
}
