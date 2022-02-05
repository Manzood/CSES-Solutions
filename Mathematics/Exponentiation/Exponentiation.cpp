#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int mod = (int) 1e9+7;

int binexp (int a, int b, int m) {
    if (b == 0) return 1;
    int val = binexp (a, b / 2, m);
    return ((val * val % m) * (b & 1 ? a : 1) % m);
}

void solve() {
    int a, b;
    scanf("%lld%lld", &a, &b);
    int ans = binexp (a, b, mod);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
