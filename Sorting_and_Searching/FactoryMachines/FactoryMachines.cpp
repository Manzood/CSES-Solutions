#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(vector<int>& a, int val, int t) {
    int n = (int)a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += val / a[i];
        if (cnt >= t) return true;
    }
    return cnt >= t;
}

void solve([[maybe_unused]] int test) {
    int n, t;
    scanf("%lld%lld", &n, &t);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int low = 0, high = (int)1e18 + 7;
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(a, mid, t)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    printf("%lld\n", high);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
