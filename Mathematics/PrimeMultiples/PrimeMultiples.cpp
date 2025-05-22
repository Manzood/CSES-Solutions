#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int get(int n, int k, vector<int>& a) {
    set<int> values;
    for (int i = 0; i < k; i++) {
        for (int j = a[i]; j <= n; j += a[i]) {
            values.insert(j);
        }
    }
    return (int)values.size();
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(k);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        scanf("%lld", &a[i]);
        ans += n / a[i];
    }
    int sub = 0;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int val = a[i] * a[j];
            if (val < a[i]) continue;
            sub += n / val;
        }
    }
    ans -= sub;
    printf("%lld\n", ans);

    map<int, int> mp = {{1, 2}, {2, 3}};
    vector<vector<vector<int>>> x = {
        {{1, 2}, {1, 3}}, {{1, 4}, {1, 5}}, {{1, 6}, {1, 7}}};
    // debug(a, mp);
    // debug(x);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
