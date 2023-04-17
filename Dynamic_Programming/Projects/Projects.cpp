#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = (int)5e5;

void coordinate_compression(vector<int>& a) {
    int n = (int)a.size();
    vector<int> d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
        a[i] = (int)(lower_bound(d.begin(), d.end(), a[i]) - d.begin());
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n), p(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &a[i], &b[i], &p[i]);
    }
    vector<int> combined = a;
    for (int i = 0; i < n; i++) combined.push_back(b[i]);
    coordinate_compression(combined);
    vector<vector<int>> ends(MX);
    for (int i = 0; i < n; i++) {
        a[i] = combined[i];
        b[i] = combined[i + n];
        ends[b[i]].push_back(i);
    }
    vector<int> dp(MX, 0);
    for (auto ind : ends[0]) {
        dp[0] = max(dp[0], p[ind]);
    }
    for (int i = 1; i < MX; i++) {
        for (auto ind : ends[i]) {
            if (a[ind] > 0)
                dp[i] = max(dp[i], dp[a[ind] - 1] + p[ind]);
            else
                dp[i] = max(dp[i], p[ind]);
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    printf("%lld\n", dp[MX - 1]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
