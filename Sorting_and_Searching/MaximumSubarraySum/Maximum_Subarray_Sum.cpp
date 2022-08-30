#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    int s = 0;
    int ans = -1e9 + 7;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s += a[i];
        ans = max (s, ans);
        if (s < 0) s = 0;
    }
    printf("%lld\n", ans);
}
