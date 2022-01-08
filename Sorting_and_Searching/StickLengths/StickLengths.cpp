#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.begin(), a.end());
    vector <int> left(n, 0), right(n, 0);
    for (int i = 1; i < n; i++) {
        left[i] = left[i-1] + i * (a[i] - a[i-1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        // left[i] = left[i-1] + i * (a[i] - a[i-1]);
        right[i] = right[i+1] + (n - i - 1) * (a[i+1] - a[i]);
    }
    int ans = (int) 1e18 + 8;
    for (int i = 0; i < n; i++) {
        ans = min (ans, left[i] + right[i]);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
