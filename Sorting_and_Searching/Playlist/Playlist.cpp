#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    int cur = 0;
    set <int> used;
    map <int, int> last_pos;
    for (int i = 0; i < n; i++) {
        cur++;
        if (used.count(a[i])) {
            cur = min(cur, i - last_pos[a[i]]);
        }
        last_pos[a[i]] = i;
        used.insert(a[i]);
        ans = max (cur, ans);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
