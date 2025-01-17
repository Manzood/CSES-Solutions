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
    int n;
    scanf("%lld", &n);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = a[0][0] != '*';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) (dp[i][j] += dp[i - 1][j]) %= MOD;
            if (j > 0) (dp[i][j] += dp[i][j - 1]) %= MOD;
            if (a[i][j] == '*') dp[i][j] = 0;
        }
    }
    printf("%lld\n", dp[n - 1][n - 1]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
