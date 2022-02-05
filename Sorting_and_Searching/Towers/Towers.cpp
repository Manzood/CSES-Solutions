#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    vector <int> towers;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(towers.begin(), towers.end(), a[i]);
        int ind = it - towers.begin();
        if (it == towers.end()) {
            towers.push_back(a[i]);
        } else {
            towers[ind] = a[i];
        }
    }
    printf("%lld\n", (int) towers.size());
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
