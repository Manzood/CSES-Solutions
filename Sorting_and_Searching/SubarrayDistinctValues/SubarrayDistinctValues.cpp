#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    map<int, int> mp;
    int sz = 0;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < n; right++) {
        int val = mp[a[right]]++;
        if (val == 0) {
            sz++;
        }
        while (sz > k) {
            val = --mp[a[left]];
            left++;
            if (val == 0) sz--;
        }
        ans += (right - left + 1);
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
