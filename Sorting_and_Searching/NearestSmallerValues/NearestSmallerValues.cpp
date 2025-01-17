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
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    stack<int> st;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top() + 1;
        st.push(i);
    }

    for (int i = 0; i < n; i++) printf("%lld%c", ans[i], " \n"[i == n - 1]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
