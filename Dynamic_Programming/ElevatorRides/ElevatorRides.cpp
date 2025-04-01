#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    // dp[i] = best answer for mask i
    // go through the array, try to improve the answer for each mask with each
    // index
    // - n * (2 ** n)
    auto print = [](const int& n) { cout << n << " "; };
}

int32_t main() {
    int t = 1;
    /* cin >> t; */
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
