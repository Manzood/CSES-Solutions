#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX_N = (int)20;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int ans = 0;
    if (n % 4 == 1 || n % 4 == 2) {
        printf("%lld\n", ans);
        return;
    }
    ans = 1;
    vector<int> f;
    vector<int> s;
    int start = 1;
    if (n % 4 == 3) {
        f.push_back(1);
        f.push_back(2);
        s.push_back(3);
        start = 4;
    }
    for (int i = start; i <= n; i += 4) {
        f.push_back(i);
        f.push_back(i + 3);
        s.push_back(i + 1);
        s.push_back(i + 2);
    }
    // get dp solution
    vector<bool> pos(MX_N, false);
    pos[0] = true;
    for (int i = 0; i < (int)f.size(); i++) {
        vector<bool> prev = pos;
        for (int j = 0; j < MX_N; j++) {
            if (j - f[i] >= 0) {
                pos[j] = pos[j] | prev[j - f[i]];
            }
        }
    }
    // cnt should be calculated differently
    vector<int> cnt(MX_N, 0);
    cnt[0] = 1;
    for (int i = 0; i < (int)s.size(); i++) {
        vector<int> prev = cnt;
        for (int j = 0; j < MX_N; j++) {
            if (j - s[i] >= 0) {
                cnt[j] += cnt[j - s[i]];
            }
        }
    }
    int sum = (n * (n + 1)) / 4;
    for (int i = 0; i < MX_N && i < sum; i++) {
        if (pos[i] == true) {
            ans *= max(cnt[i], 1LL);
        }
        // if (cnt[i]) {
        //     ans *= cnt[i] + (pos[i] == true);
        // }
    }
    debug(f, s);
    debug(pos);
    debug(cnt);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
