#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    iota(a.begin(), a.end(), 1LL);
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        printf("0\n");
        return;
    }
    int cnt = 0;
    for (int i = 0; i < (1LL << n); i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1LL << j)) {
                s += a[j];
            }
        }
        if (s == sum / 2) {
            cnt++;
        }
    }
    assert((cnt & 1) == 0);
    printf("%lld\n", cnt / 2);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
