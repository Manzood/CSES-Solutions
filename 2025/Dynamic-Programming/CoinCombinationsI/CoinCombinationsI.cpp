#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &coins[i]);
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto c : coins) {
            if (i - c >= 0) (dp[i] += dp[i - c]) %= INF;
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
