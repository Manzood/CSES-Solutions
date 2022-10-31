#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pref[i + 1][j] += pref[i][j];
            pref[i][j + 1] += pref[i][j];
            pref[i + 1][j + 1] -= pref[i][j];
            if (a[i][j] == '*') {
                pref[i + 1][j + 1]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        pref[i + 1][n] += pref[i][n];
        pref[n][i + 1] += pref[n][i];
    }
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        // debug(pref[x2][y2]);
        // debug(pref[x1 - 1][y2]);
        // debug(pref[x2][y1 - 1]);
        // debug(pref[x1 - 1][y1 - 1]);
        int ans = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] +
                  pref[x1 - 1][y1 - 1];
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
