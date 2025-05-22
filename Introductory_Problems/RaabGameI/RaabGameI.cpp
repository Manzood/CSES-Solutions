#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    bool possible = true;
    if (a + b > n) possible = false;
    if (!possible) {
        printf("NO\n");
        return;
    }

    vector<int> x, y;
    int base = 0;
    for (int i = 0; i < n - (a + b); i++) {
        x.push_back(i + 1);
        y.push_back(i + 1);
        base++;
    }
    for (int i = 0; i < a; i++) {
        x.push_back(n - i);
        y.push_back(base + i + 1);
    }
    for (int i = 0; i < b; i++) {
        x.push_back(base + i + 1);
        y.push_back(n - i);
    }

    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", x[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", y[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
