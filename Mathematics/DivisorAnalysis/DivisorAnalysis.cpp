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
    vector<int> x(n), k(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &k[i]);
    }

    int cnt = 1;
    for (int i = 0; i < n; i++) {
        cnt *= (k[i] + 1);
        cnt %= MOD;
    }

    int sum = 0;
    // product of all divisors??
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
