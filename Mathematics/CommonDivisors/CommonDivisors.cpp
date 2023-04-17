#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int MAX_N = (int)1e6;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    vector<int> cnt(MAX_N + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
    }
    int ans = 1;
    for (int i = MAX_N; i >= 1; i--) {
        int tot = 0;
        for (int j = i; j <= MAX_N; j += i) tot += cnt[j];
        if (tot >= 2) {
            ans = i;
            break;
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
