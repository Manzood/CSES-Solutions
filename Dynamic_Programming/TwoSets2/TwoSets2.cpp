#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX_N = (int)3e5 + 5;
constexpr int mod = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    if (n % 4 == 1 || n % 4 == 2) {
        printf("0\n");
        return;
    }
    // dp[i] -> number of ways to make sum i
    vector<int> dp(MX_N, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> prev = dp;
        for (int j = i; j < MX_N; j++) {
            dp[j] += prev[j - i];
            dp[j] %= mod;
        }
    }
    int sum = (n * (n + 1)) / 4;
    printf("%lld\n", (dp[sum] & 1) ? dp[sum] / 2 + 1 : dp[sum] / 2);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
