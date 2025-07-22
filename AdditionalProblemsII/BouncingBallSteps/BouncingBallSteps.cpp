#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);

    int vcnt = 0, hcnt = 0;
    if (k >= n) {
        vcnt = 1 + (k - n) / (n - 1);
    }
    if (k >= m) {
        hcnt = 1 + (k - m) / (m - 1);
    }

    bool vflip = false, hflip = false;
    if (vcnt % 2 != 0) vflip = true;
    if (hcnt % 2 != 0) hflip = true;

    int x = k % m + 1, y = k % n + 1;
    if (k > n) {
        x = 2 + (k - n) % (n - 1);
    } else if (k == n) {
        x = 2;
    } else {
        x = 1 + k;
    }
    if (y > m) {
        y = 2 + (k - m) % (m - 1);
    } else if (y == m) {
        y = 2;
    } else {
        y = 1 + k;
    }

    if (hflip) x = m - x + 1;
    if (vflip) y = n - y + 1;

    if (test == 3) debug(k == n);

    int changes = vcnt + hcnt +
                  (k == n || (k > n && ((k - n) % (n - 1) == 0))) +
                  (k == m || (k > m && ((k - m) % (m - 1) == 0)));

    printf("%lld %lld %lld\n", x, y, changes);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
