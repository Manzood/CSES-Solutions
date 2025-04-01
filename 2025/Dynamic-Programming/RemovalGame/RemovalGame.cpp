#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

int n;
bool turn(int sz) {
    if ((n - sz) & 1) return 1;
    return 0;
}

vector<vector<pair<int, int>>> dp;
pair<int, int> get(int left, int right, vector<int>& a) {
    pair<int, int> ret = {-INF, -INF};
    if (left > right) return {0, 0};
    if (dp[left][right].first != -INF) return dp[left][right];
    bool cur = turn(right - left + 1);
    if (!cur) {
        pair<int, int> choose = get(left + 1, right, a);
        choose.first += a[left];
        ret = max(ret, choose);
        choose = get(left, right - 1, a);
        choose.first += a[right];
        ret = max(ret, choose);
    } else {
        pair<int, int> choose = get(left + 1, right, a);
        choose.second += a[left];
        if (choose.second > ret.second) ret = choose;
        choose = get(left, right - 1, a);
        choose.second += a[right];
        if (choose.second > ret.second) ret = choose;
    }
    return dp[left][right] = ret;
}

void solve([[maybe_unused]] int test) {
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    dp.assign(n, vector<pair<int, int>>(n, {-INF, -INF}));
    pair<int, int> ans = get(0, n - 1, a);
    printf("%lld\n", ans.first);
}

int32_t main() {
    int t = 1;
    /* cin >> t; */
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
