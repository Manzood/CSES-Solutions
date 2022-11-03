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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] %= n;
    }
    map<int, int> sum;
    sum[0]++;
    int tot = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        tot = (tot + a[i]) % n;
        if (tot < 0) tot += n;
        if (sum.count(tot)) {
            ans += sum[tot];
        }
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
