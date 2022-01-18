#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

vector<vector<int>> ans;
void TowerOfHanoi(int src, int dest, int util, int num) {
    if (num == 0) return;
    TowerOfHanoi (src, util, dest, num - 1);
    // move to tower dest
    ans.push_back ({src, dest});
    TowerOfHanoi (util, dest, src, num - 1);
}

void solve() {
    int n;
    scanf("%lld", &n);
    TowerOfHanoi(1, 3, 2, n);
    printf("%lld\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%lld %lld\n", ans[i][0], ans[i][1]);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
