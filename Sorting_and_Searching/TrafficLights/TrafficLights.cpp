#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &x, &n);
    vector<int> a(n);
    map<int, int> d;
    d[x]++;
    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        // get previous, next
        if (a[i] == x || a[i] == 0) continue;
        auto next = lower_bound(lights.begin(), lights.end(), a[i]);
        auto previous = next;
        previous--;
        int left = a[i] - *previous;
        int right = *next - a[i];
        int cur = *next - *previous;
        // debug(*previous, *next, cur);
        // for (auto temp : d) {
        // printf("%lld ", temp);
        // }
        // printf("\n");
        // for (auto temp : d) {
        //     printf("%lld ", temp.first);
        // }
        // printf("\n");
        // printf("%lld\n", (*d.rbegin()).first);
        d[cur]--;
        if (d[cur] == 0) d.erase(d.find(cur));
        d[left]++;
        d[right]++;
        lights.insert(a[i]);
        printf("%lld ", (*d.rbegin()).first);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
