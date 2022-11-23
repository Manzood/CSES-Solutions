#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<pair<int, pair<int, int>>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second.first);
        a[i].second.second = i;
    }
    sort(a.begin(), a.end(),
         [](pair<int, pair<int, int>> i, pair<int, pair<int, int>> j) -> bool {
             return (i.first == j.first && i.second.first > j.second.first) ||
                    i.first < j.first;
         });
    vector<vector<int>> ans(n, {0, 0});
    indexed_set s;
    // number of ranges that the current range contains;
    for (int i = n - 1; i >= 0; i--) {
        int ind = s.order_of_key(a[i].second.first + 1);
        ans[a[i].second.second][0] = ind;
        if (i == 1) {
            debug(a[i]);
            debug(s.size());
        }
        s.insert(a[i].second.first);
    }
    s.clear();
    sort(a.begin(), a.end(),
         [](pair<int, pair<int, int>> i, pair<int, pair<int, int>> j) -> bool {
             return (i.first == j.first && i.second.first < j.second.first) ||
                    i.first < j.first;
         });
    // number of ranges that contain the current range
    for (int i = 0; i < n; i++) {
        int ind = (int)s.size() - s.order_of_key(a[i].second.first);
        ans[a[i].second.second][1] = ind;
        s.insert(a[i].second.first);
    }
    // calculate everything less than or equal to current element
    for (int i = 0; i < n; i++) {
        printf("%lld%c", ans[i][0], " \n"[i == n - 1]);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", ans[i][1], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
