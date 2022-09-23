#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MAX_N = (int)1e5 + 1;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    vector<bool> dp(MAX_N, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = MAX_N - 1; j >= 0; j--) {
            if (j - a[i] >= 0) {
                dp[j] = dp[j] | dp[j - a[i]];
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i < MAX_N; i++) {
        if (dp[i]) ans.push_back(i);
    }
    printf("%lld\n", (int)ans.size());
    for (auto x : ans) {
        printf("%lld ", x);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
