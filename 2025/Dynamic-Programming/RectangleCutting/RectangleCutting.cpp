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
    int a, b;
    scanf("%lld%lld", &a, &b);
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INF));
    for (int i = 0; i <= min(a, b); i++) dp[i][i] = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 1; k <= min(i, j); k++) {
                int v1 = j > k ? 1 + dp[i][j - k] : 0;
                v1 += i > k ? 1 + dp[i - k][k] : 0;
                int v2 = i > k ? 1 + dp[i - k][j] : 0;
                v2 += j > k ? 1 + dp[k][j - k] : 0;
                dp[i][j] = min({dp[i][j], v1, v2});
            }
        }
    }
    printf("%lld\n", dp[a][b]);
}

int32_t main() {
    int t = 1;
    /* cin >> t; */
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
