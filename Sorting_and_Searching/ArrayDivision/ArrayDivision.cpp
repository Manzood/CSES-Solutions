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
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int jump = (n + k - 1) / k;
    debug(jump);
    vector<int> val(k, 0);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += jump) {
            val[i] += a[j];
        }
        ans = max(ans, val[i]);
    }
    debug(val);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
