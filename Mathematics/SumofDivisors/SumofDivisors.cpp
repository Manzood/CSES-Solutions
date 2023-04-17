#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        (ans += i) %= MOD;
        int num = (n - i * i) / i;
        int first_term = 2 * ((i * i % MOD) + i % MOD) % MOD;
        int second_term = ((num % MOD) - 1) * i % MOD;
        if (second_term < MOD) second_term += MOD;
        int prod = (num % MOD) * (first_term + second_term % MOD) % MOD;
        (ans += (prod * inv(2, MOD) % MOD) * inv(i, MOD) % MOD) %= MOD;
        (ans += ((num % MOD) * i % MOD)) %= MOD;
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
