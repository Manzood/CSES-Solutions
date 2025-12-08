#include "bits/stdc++.h"

#ifdef local
#include "custom/tempDebugger.h"
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
    vector<vector<pair<int, int>>> prev(
        n + 1, vector<pair<int, int>>(
                   m + 1, {-1, -1}));  // keeps track of the previous increase
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prev[i + 1][j + 1] = prev[i][j];
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                prev[i + 1][j + 1] = {i, j};
            } else {
                if (dp[i][j + 1] > dp[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                    prev[i + 1][j + 1] = prev[i][j + 1];
                }
                if (dp[i + 1][j] > dp[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                    prev[i + 1][j + 1] = prev[i + 1][j];
                }
            }
        }
    }

    vector<int> ans;
    pair<int, int> cur = prev[n][m];
    while (cur != make_pair(-1LL, -1LL)) {
        assert(cur.first >= 0 && cur.second >= 0);
        ans.push_back(a[cur.first]);
        if (prev[cur.first][cur.second] == cur) {
            cur.first--;
            cur.second--;
        } else {
            cur = prev[cur.first][cur.second];
        }
    }

    assert((int)ans.size() == dp[n][m]);
    printf("%lld\n", dp[n][m]);
    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        printf("%lld ", x);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
