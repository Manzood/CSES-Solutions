#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int LOG = 32, INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    vector<vector<int>> table(n, vector<int>(LOG, INF));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        table[i][0] = a[i];
        for (int j = 1; j < LOG && (i - (1LL << j) + 1) >= 0; j++) {
            table[i][j] =
                min(table[i][j - 1], table[i - (1LL << (j - 1))][j - 1]);
        }
    }
    for (int query = 0; query < q; query++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x--, y--;
        int cur = y;
        int ans = INF;
        while (cur >= x) {
            int diff = cur - x;
            int p = 1, cnt = 0;
            while (p * 2 <= diff) {
                p *= 2;
                cnt++;
            }
            ans = min(ans, table[cur][cnt]);
            cur -= p;
        }
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
