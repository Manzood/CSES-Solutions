#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        x ^= a[i];
    }

    bool ans = x != 0;

    printf(ans ? "first\n" : "second\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
