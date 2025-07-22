#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

long long power(long long a, long long b, long long m) {
    long long result = 1;
    while (b) {
        if (b % 2 == 1) result = result * a % m;
        a = a * a % m;
        b /= 2;
    }
    return result;
}

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> p(n), alpha(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &p[i], &alpha[i]);
    }
    int num = 1;
    for (int i = 0; i < n; i++) {
        (num *= alpha[i] + 1) %= MOD;
    }
    int sum = 1;
    for (int i = 0; i < n; i++) {
        int cur = power(p[i], alpha[i] + 1, MOD);
        (cur += MOD - 1) %= MOD;
        int div = inv(p[i] - 1, MOD);
        (cur *= div) %= MOD;
        (sum *= cur) %= MOD;
    }
    int prod = 1;
    int numcopy = 1;
    for (int i = 0; i < n; i++) {
        (numcopy *= alpha[i] + 1) %= (MOD - 1);
    }
    for (int i = 0; i < n; i++) {
        int v1 = (numcopy * inv(alpha[i] + 1, MOD - 1)) % (MOD - 1);
        int v2 = (alpha[i] * (alpha[i] + 1) / 2) % (MOD - 1);
        (v1 *= v2) %= (MOD - 1);
        int cur = power(p[i], v1, MOD);
        (prod *= cur) %= MOD;
    }
    printf("%lld %lld %lld\n", num, sum, prod);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
