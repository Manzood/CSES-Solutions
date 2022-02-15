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
    vector <vector <int>> a(n, vector <int> (2));
    for (int i = 0; i < n; i++) {
        int x; scanf("%lld", &x);
        a[i][0] = x;
        a[i][1] = i;
    }
    sort (a.begin(), a.end());
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i][1] < a[i-1][1]) {
            ans++;
        }
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
