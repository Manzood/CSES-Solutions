#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }

    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
        return (x.second == y.second) ? x.first < y.first : x.second < y.second;
    });

    // choose the *last* free person
    multiset<int> q;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!q.empty() && *q.begin() <= a[i].first) {
            auto it = q.upper_bound(a[i].first);
            it--;
            q.erase(it);

            q.insert(a[i].second);
            ans++;
        } else if ((int)q.size() < k) {
            q.insert(a[i].second);
            ans++;
        }
        // debug(i, ans, *q.begin(), q.size());
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
