#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> last(n + 1, vector<int>(m + 1, -1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                last[i][j] = i - 1;
            } else {
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    dp[i][j] = dp[i][j - 1];
                    last[i][j] = last[i][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                    last[i][j] = last[i - 1][j];
                }
            }
        }
    }
    printf("%lld\n", dp[n][m]);
    int cur = last[n][m];
    if (dp[n][m] > 0) {
        vector<int> out;
        while (cur >= 0) {
            out.push_back(a[cur]);
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
