#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;

long long power(long long a, long long b, long long m) {
    long long result = 1;
    while (b) {
        if (b % 2 == 1) result = result * a % m;
        a = a * a % m;
        b /= 2;
    }
    return result;
}

void solve() {
    int a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    int exp = power(b, c, mod - 1);
    int ans = power(a, exp, mod);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
