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
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &coins[i]);
    }

    sort(coins.begin(), coins.end());
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - coins[i] < 0) continue;
            (dp[j] += dp[j - coins[i]]) %= MOD;
        }
    }

    printf("%lld\n", dp[x]);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
