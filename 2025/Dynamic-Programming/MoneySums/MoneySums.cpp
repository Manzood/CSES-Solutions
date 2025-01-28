#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = (int)1e5 + 1;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<bool> possible(MX, false);
    possible[0] = true;
    for (int i = 0; i < n; i++) {
        vector<bool> next_possible = possible;
        for (int j = a[i]; j < MX; j++) {
            if (possible[j - a[i]]) next_possible[j] = true;
        }
        possible = next_possible;
    }
    vector<int> ans;
    for (int i = 1; i < MX; i++)
        if (possible[i]) ans.push_back(i);
    printf("%lld\n", (int)ans.size());
    for (auto x : ans) {
        printf("%lld ", x);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    /* cin >> t; */
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
