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
    unordered_map<int, pair<int, int>> suff;
    unordered_map<int, int> freq;
    vector<vector<int>> added(n);
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] >= x - 1) continue;
            suff[a[i] + a[j]] = {i, j};
            freq[a[i] + a[j]]++;
            added[i].push_back(a[i] + a[j]);
        }
    }
    vector<int> ans;
    for (int i = 1; i < n - 2; i++) {
        for (auto f : added[i]) {
            int val = --freq[f];
            if (val == 0) {
                suff.erase(f);
            }
        }
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] + a[j] >= x) continue;
            int val = x - (a[i] + a[j]);
            if (suff.count(val)) {
                ans = {i, j, suff[val].first, suff[val].second};
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
