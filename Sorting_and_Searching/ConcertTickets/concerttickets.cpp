#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <int> a(n), b(m);
    multiset <int> ms;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ms.insert (a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    // sort (a.begin(), a.end());
    vector <int> ans(m);
    for (int i = 0; i < m; i++) {
        auto it = ms.upper_bound(b[i]);
        if (it == ms.begin()) {
            ans[i] = -1;
        } else {
            it = prev(it);
            ans[i] = *it;
            ms.erase (it);
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%lld\n", ans[i]);
    }
}
