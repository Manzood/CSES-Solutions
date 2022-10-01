#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x, n;
    scanf("%lld%lld", &n, &x);
    vector<int> lights(n + 2);
    lights[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &lights[i + 1]);
    }
    lights[n + 1] = x;
    multiset<int> s;
    // what was the previous value of the segment
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
