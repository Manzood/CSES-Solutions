#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int MX = (int)1e15;

bool possible(vector<int>& a, int s, int k) {
    int n = (int)a.size();
    int subs = 1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > s) return false;
        if (cur + a[i] <= s) {
            cur += a[i];
        } else {
            subs++;
            cur = a[i];
        }
    }
    if (s == 3) debug(subs);
    return subs <= k;
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int low = 1, high = MX;
    while (low < high) {
        int mid = (low + high) / 2;
        if (possible(a, mid, k)) {
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
