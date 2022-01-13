#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long
const int mod = (int)1e9 + 7;

void solve() {
    int n;
    scanf("%lld", &n);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && i - j >= 0; j++) {
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }
    printf("%lld\n", dp[n]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
