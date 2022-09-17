#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    vector<int> dp(n + 1, INF);
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[ind] = a[i];
    }
    int ans = 0;
    for (int i = 0; i < n + 1; i++) {
        if (dp[i] < INF) ans = i + 1;
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
