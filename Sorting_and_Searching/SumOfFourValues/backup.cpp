#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<map<int, pair<int, int>>> suff(n);
    // since you're using a map, you can also keep track of number of occurences
    // and keep track of the values being added at each index
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1];
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] >= x - 1) continue;
            suff[i][a[i] + a[j]] = {i, j};
        }
    }
    debug(suff[0].size());
    vector<int> ans;
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            if (a[i] + a[j] >= x) continue;
            if (suff[j + 1].count(x - (a[i] + a[j]))) {
                pair<int, int> val = suff[j + 1][x - (a[i] + a[j])];
                ans = {i, j, val.first, val.second};
            }
        }
    }
    if (ans.empty()) {
        printf("IMPOSSIBLE\n");
    } else {
        for (int i = 0; i < 4; i++) {
            printf("%d%c", ans[i] + 1, " \n"[i == 3]);
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
