#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, t;
    scanf("%lld%lld", &n, &t);
    vector<int> a(n);
    float inv = 0.0f;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        inv += (float)1.0f / a[i];
    }
    int ans = 0;
    int low = 1;
    int high = (int)1e9 + 7;
    while (low <= high) {
        int mid = (low + high) / 2;
        int val = (int)((float)mid * inv);
        if (val >= t) {
            debug((float)mid * inv);
            ans = val;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
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
