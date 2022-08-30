#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void recompute(int val, vector<bool>& present, vector<int>& index) {
    int n = (int)present.size() - 1;
    present[val] = val > 1 ? index[val - 1] < index[val] : false;
    if (val < n) {
        val++;
        present[val] = val > 1 ? index[val - 1] < index[val] : false;
    }
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<bool> present(n + 1, false);
    vector<bool> found(n + 1, false);
    vector<int> index(n + 1, -1);
    for (int i = 0; i < n; i++) {
        if (found[a[i] - 1]) present[a[i]] = true;
        found[a[i]] = true;
        index[a[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!present[i]) ans++;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x = a[x - 1];
        y = a[y - 1];
        int x_ind = index[y];
        int y_ind = index[x];
        index[x] = x_ind;
        index[y] = y_ind;
        a[index[x]] = x;
        a[index[y]] = y;
        if (!present[x]) ans--;
        if (!present[y]) ans--;
        if (x + 1 <= n && x + 1 != y && !present[x + 1]) ans--;
        if (y + 1 <= n && y + 1 != x && !present[y + 1]) ans--;
        recompute(x, present, index);
        recompute(y, present, index);
        if (!present[x]) ans++;
        if (!present[y]) ans++;
        if (x + 1 <= n && x + 1 != y && !present[x + 1]) ans++;
        if (y + 1 <= n && y + 1 != x && !present[y + 1]) ans++;
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
