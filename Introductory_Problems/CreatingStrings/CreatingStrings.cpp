#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    string s;
    cin >> s;
    vector<string> ans;
    sort (s.begin(), s.end());
    do {
        ans.push_back (s);
    } while (next_permutation(s.begin(), s.end()));
    printf("%lld\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
