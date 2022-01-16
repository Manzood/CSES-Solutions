#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    bool possible = false;
    if (n % 4 == 0 || (n - 3) % 4 == 0) {
        possible = true;
    }
    vector <int> ans1, ans2;
    if (n % 4 == 0) {
        for (int i = 1; i <= n; i++) {
            if (i % 4 == 0 || i % 4 == 1) {
                ans1.push_back (i);
            } else {
                ans2.push_back (i);
            }
        }
    } else if (possible) {
        ans1.push_back (1);
        ans1.push_back (2);
        ans2.push_back (3);
        for (int i = 4; i <= n; i++) {
            if (i % 4 == 0 || i % 4 == 3) {
                ans1.push_back (i);
            } else {
                ans2.push_back (i);
            }
        }
    }
    if (possible) {
        printf("YES\n");
        printf("%lld\n", (int) ans1.size());
        for (int i = 0; i < (int) ans1.size(); i++) {
            printf("%lld ", ans1[i]);
        }
        printf("\n");
        printf("%lld\n", (int) ans2.size());
        for (int i = 0; i < (int) ans2.size(); i++) {
            printf("%lld ", ans2[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
