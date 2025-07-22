#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    map<int, int> occ;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        occ[a[i]]++;
    }

    int ans = 1;
    for (auto pp : occ) {
        ans *= (pp.second + 1);
        ans %= MOD;
    }

    ans--;
    if (ans < 0) ans += MOD;

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
