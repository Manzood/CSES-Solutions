#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;

// in the future: consider solving this with just dp[n][2];
// where dp[i][0]] represents whether row i has a divider in between, and
// dp[i][1] represents whether it does not. all closing and opening of rows can
// be handled in the transitions, instead of the state

// you can refer to https://www.youtube.com/watch?v=ac0KMjR2HwI if you're stuck

vector<vector<int>> dp;
int MAX_N = (int)1e6 + 1;
void precompute() {
    dp[0][0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] +
                   dp[i - 1][5];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][4];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] +
                   dp[i - 1][5];
        dp[i][3] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] +
                   dp[i - 1][5];
        dp[i][4] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][4];
        dp[i][5] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] +
                   dp[i - 1][5];
        for (int j = 0; j < 6; j++) {
            dp[i][j] %= mod;
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int ans = dp[n][0] + dp[n][1];
    printf("%lld\n", ans % mod);
}

int32_t main() {
    int t = 1;
    scanf("%lld", &t);
    dp.resize(MAX_N);
    dp.assign(MAX_N, vector<int>(6, 0));
    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
