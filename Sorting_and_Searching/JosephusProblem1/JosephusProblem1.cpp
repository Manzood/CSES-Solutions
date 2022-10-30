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
    indexed_set s;
    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }
    auto it = s.begin();
    while ((int)s.size() > 0) {
        it++;
        if (it == s.end()) it = s.begin();
        auto next = it;
        next++;
        if (next == s.end()) next = s.begin();
        printf("%lld ", *it);
        s.erase(it);
        it = next;
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
