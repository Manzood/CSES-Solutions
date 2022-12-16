#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;
constexpr int MX_N = (int)1e6 + 5;
vector<int> factorial(MX_N);

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void precompute() {
    factorial[0] = 1;
    for (int i = 1; i < MX_N; i++) {
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= mod;
    }
}

void solve([[maybe_unused]] int test) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    int ans = (factorial[a] * inv(factorial[b], mod) % mod) *
              inv(factorial[a - b], mod) % mod;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
