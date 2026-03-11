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
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = i - 1; j >= i - 6 && j >= 0; j--) {
            (dp[i] += dp[j]) %= MOD;
        }
    }
    printf("%lld\n", dp[n]);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
