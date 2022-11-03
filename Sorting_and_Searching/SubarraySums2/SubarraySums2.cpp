#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    map<int, int> sum;
    sum[0]++;
    int tot = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int val = (tot + a[i]) - x;
        if (sum.count(val)) {
            ans += sum[val];
        }
        tot += a[i];
        sum[tot]++;
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
