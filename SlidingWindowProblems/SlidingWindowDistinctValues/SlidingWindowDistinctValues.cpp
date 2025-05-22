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
    for (int i = 0; i < k; i++) {
        mp[a[i]]++;
    }
    vector<int> ans;
    ans.push_back(mp.size());
    for (int i = k; i < n; i++) {
        mp[a[i - k]]--;
        if (mp[a[i - k]] == 0) {
            mp.erase(a[i - k]);
        }
        mp[a[i]]++;
        ans.push_back(mp.size());
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
