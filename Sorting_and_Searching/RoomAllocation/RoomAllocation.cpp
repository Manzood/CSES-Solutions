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
    vector<pair<int, int>> start(n), end(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &start[i].first, &end[i].first);
        start[i].second = i;
        end[i].second = i;
    }
    vector<int> f(n);
    iota(f.begin(), f.end(), 0);
    reverse(f.begin(), f.end());
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int cnt = 0, tot = 0;
    int s = 0, e = 0;
    vector<int> ans(n), assigned(n, -1);
    while (s < n) {
        if (start[s].first <= end[e].first) {
            // new room
            cnt++;
            ans[start[s].second] = f.back();
            f.pop_back();
            s++;
        } else {
            cnt--;
            f.push_back(ans[end[e].second]);
            e++;
        }
        tot = max(cnt, tot);
    }
    printf("%lld\n", tot);
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i] + 1);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
