#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<pair<int, pair<int, int>>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second.first);
        a[i].second.second = i;
    }
    sort(a.begin(), a.end(), [](auto i, auto j) -> bool {
        return (i.first == j.first && i.second.first > j.second.first) ||
               i.first < j.first;
    });
    vector<pair<int, int>> ans(n, {false, false});
    int mi = (int)1e9 + 7;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i].second.first >= mi) {
            ans[a[i].second.second].first = true;
        }
        mi = min(a[i].second.first, mi);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second.first <= mx) {
            ans[a[i].second.second].second = true;
        }
        mx = max(a[i].second.first, mx);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", ans[i].first, " \n"[i == n - 1]);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", ans[i].second, " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
