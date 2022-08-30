#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

constexpr int INF = (int)1e9 + 7;

void solve() {
    int n;
    scanf("%lld", &n);
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int val = i;
        // get digits
        while (val) {
            int digit = val % 10;
            if (i - digit >= 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
            val /= 10;
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
