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
    int x, a, b, c;
    scanf("%lld%lld%lld%lld", &x, &a, &b, &c);

    int cxor = x;
    vector<int> vals(n);
    vals[0] = x;
    for (int i = 1; i < k; i++) {
        x = (a * x + b) % c;
        vals[i] = x;
        cxor ^= x;
    }

    int out = cxor;
    for (int i = k; i < n; i++) {
        x = (a * x + b) % c;
        cxor ^= vals[i - k];
        cxor ^= x;
        vals[i] = x;
        out ^= cxor;
    }

    printf("%lld\n", out);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
