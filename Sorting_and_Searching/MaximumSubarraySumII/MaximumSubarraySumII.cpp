#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18 + 7;

void solve([[maybe_unused]] int test) {
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    vector<int> a(n), pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pref[i + 1] = pref[i] + a[i];
    }

    stack<int> st;
    vector<int> nse(n + 1, -1);
    for (int i = n; i >= 0; i--) {
        while (!st.empty() && pref[st.top()] >= pref[i]) st.pop();
        if (!st.empty()) nse[i] = st.top();
        st.push(i);
    }

    int l = 0, r = 0;
    int ans = -INF;
    int cur = 0;

    for (int i = x - 1; i < n; i++) {
        while (r <= i) cur += a[r++];
        while (l < r - y) cur -= a[l++];

        int nxt = nse[l];
        int prev = -1;
        while (nxt != prev && r - nxt >= x) {
            prev = nxt;
            while (l < nxt) cur -= a[l++];
            nxt = nse[l];
        }

        ans = max(ans, cur);
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
