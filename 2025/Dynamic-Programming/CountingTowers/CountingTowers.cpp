#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7, N = (int)1e6 + 1;

vector<vector<int>> dp(N, vector<int>(6, 0));
void preCompute() {
    // relationships:
    // 0 -> 0, 1, 3, 4, 5
    // 1 -> 0, 1, 3, 4, 5
    // 2 -> 0, 2, 3
    // 3 -> 0, 2, 3
    // 4 -> 0, 1, 3, 4, 5
    // 5 -> 0, 1, 3, 4, 5
    for (int i = 0; i < 6; i++) dp[0][i] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4] +
                    dp[i - 1][5]) %
                   MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4] +
                    dp[i - 1][5]) %
                   MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][3] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][4] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4] +
                    dp[i - 1][5]) %
                   MOD;
        dp[i][5] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4] +
                    dp[i - 1][5]) %
                   MOD;
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    printf("%lld\n", (dp[n - 1][0] + dp[n - 1][3]) % MOD);
}

int32_t main() {
    int t = 1;
    cin >> t;
    preCompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
