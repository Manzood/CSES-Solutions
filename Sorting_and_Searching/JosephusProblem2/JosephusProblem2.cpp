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
    int n, k;
    scanf("%lld%lld", &n, &k);
    indexed_set s;
    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }
    int idx = k;
    while (s.size() > 0) {
        if ((int)s.size() == 0) break;
        idx %= (int)s.size();
        auto it = s.find_by_order(idx);
        printf("%lld ", *it);
        s.erase(it);
        idx += k;
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
