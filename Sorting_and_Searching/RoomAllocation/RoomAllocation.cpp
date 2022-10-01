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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j = 0;
    int mx = 0;
    vector<int> ans(n);
    // find mex??
    for (int i = 0; i < n; i++) {
        while (j < n && b[j] < a[i]) j++;
        int req = i - j + 1;
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
