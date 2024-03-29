#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX_N = (int)3e5 + 5;
constexpr int mod = (int)1e9 + 7;

long long inv(long long a, long long modulo) {
    return 1 < a ? modulo - inv(modulo % a, a) * modulo / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        printf("0\n");
        return;
    }
    vector<int> dp(MX_N, 0LL);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> old_dp = dp;
        for (int j = i; j < MX_N; j++) {
            dp[j] += old_dp[j - i];
            dp[j] %= mod;
        }
    }
    // assert(dp[sum / 2] % 2 == 0);
    int val = inv(2, mod);
    printf("%lld\n", (dp[sum / 2] * val % mod));
    // modular inverse?
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
