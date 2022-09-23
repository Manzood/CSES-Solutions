#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18 + 7;

vector<vector<pair<int, int>>> dp;
pair<int, int> getans(int left, int right, int turn, vector<int>& a) {
    if (dp[left][right] != make_pair(-INF, -INF)) return dp[left][right];
    if (left == right) {
        return turn ? make_pair(0LL, a[left]) : make_pair(a[left], 0LL);
    }
    pair<int, int> retval = {-INF, -INF};
    if (turn == 0) {
        retval = getans(left + 1, right, !turn, a);
        retval.first += a[left];
        pair<int, int> temp = getans(left, right - 1, !turn, a);
        temp.first += a[right];
        retval = max(retval, temp);
    } else {
        retval = getans(left + 1, right, !turn, a);
        retval.second += a[left];
        pair<int, int> temp = getans(left, right - 1, !turn, a);
        temp.second += a[right];
        if (temp.second > retval.second) {
            retval = temp;
        } else {
            retval = min(retval, temp);
        }
    }
    dp[left][right] = retval;
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (auto& x : a) {
        scanf("%lld", &x);
    }
    dp.resize(n, vector<pair<int, int>>(n, make_pair(-INF, -INF)));
    pair<int, int> ans = getans(0, n - 1, 0, a);
    printf("%lld\n", ans.first);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
