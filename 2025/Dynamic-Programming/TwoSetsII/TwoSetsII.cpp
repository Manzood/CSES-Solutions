#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
/* #define int long long */

constexpr int MX = 125251, MOD = (int)1e9 + 7;

int inv(int a, int m) { return 1 < a ? m - inv(m % a, a) * m / a : 1; }

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%d", &n);
    vector<int> sums(MX, 0);
    sums[0] = 1;
    bool found = false;
    int tot = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        vector<int> cpy = sums;
        for (int j = i; j < MX; j++) {
            if (cpy[j] + sums[j - i] > MOD) found |= j <= tot / 2;
            (cpy[j] += sums[j - i]) %= MOD;
        }
        sums = cpy;
    }
    if (found)
        printf("%d\n",
               (tot & 1)
                   ? 0
                   : (int)(((long long)sums[tot / 2] * inv(2, MOD)) % MOD));
    else
        printf("%d\n", (tot & 1) ? 0 : sums[tot / 2] / 2);
}

int32_t main() {
    int t = 1;
    /* cin >> t; */
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
