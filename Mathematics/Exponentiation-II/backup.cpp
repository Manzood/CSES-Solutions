#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int mod = (int)1e9 + 7;

int ans = 1;

int standard_binexp(int a, int b) {
    if (b == 0) return 1;
    int val = standard_binexp(a, b / 2);
    return ((val * val % mod) * (b & 1 ? a : 1) % mod);
}

int binexp(int a, int b, int c) {
    int retval = 1;
    if (c == 0) return retval;
    int val = binexp(a, b, c / 2);  // O(log(c)) -> 32
    retval = val * val;
    assert(retval >= 0);
    if (retval >= mod) {
        int diff = retval - (retval % mod);
        assert(diff >= 0);
        ans = ans * standard_binexp(a, diff) % mod;  // O(log(diff)) -> 64
        assert(ans >= 0);
        retval %= mod;
    }
    retval = retval * (c & 1 ? b : 1);
    assert(retval >= 0);
    if (retval >= mod) {
        int diff = retval - (retval % mod);
        assert(diff >= 0);
        ans = ans * standard_binexp(a, diff) % mod;  // O(log(diff)) -> 64
        assert(ans >= 0);
        retval %= mod;
    }
    return retval;
}

void solve() {
    int a, b, c;
    ans = 1;
    scanf("%lld%lld%lld", &a, &b, &c);
    int val = binexp(a, b, c);  // 32 * 128 ops max?
    ans = ans * standard_binexp(a, val) % mod;
    assert(ans >= 0);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
