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

    int csum = x;
    vector<int> vals(n);
    vals[0] = x;
    for (int i = 1; i < k; i++) {
        x = (a * x + b) % c;
        vals[i] = x;
        csum += x;
    }

    int out = csum;
    for (int i = k; i < n; i++) {
        x = (a * x + b) % c;
        csum -= vals[i - k];
        csum += x;
        vals[i] = x;
        out ^= csum;
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
