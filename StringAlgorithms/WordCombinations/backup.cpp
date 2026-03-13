#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

void generate(string& cur, vector<string>& all, string& target, int& ans) {
    int len = (int)cur.size();
    if (len > (int)target.size()) return;
    if (len == (int)target.size()) {
        if (cur == target) ans = (ans + 1) % MOD;
        return;
    }
    for (int i = 0; i < (int)all.size(); i++) {
        cur += all[i];
        generate(cur, all, target, ans);
        for (int j = 0; j < (int)all[i].size(); j++) {
            cur.pop_back();
        }
    }
}

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int m;
    scanf("%lld", &m);
    vector<string> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    string cur;
    int ans = 0;
    generate(cur, a, s, ans);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
