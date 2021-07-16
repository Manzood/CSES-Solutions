#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int start = 0;
    int end = 0;
    int s = a[0];
    int ans = 0;
    while (start < n) {
        if (s < x) {
            if (end < n) {
                end++;
                s += a[end];
            } else {
                break;
            }
        } else if (s > x) {
            s -= a[start];
            start++;
            if (end < start) {
                end++;
                if (end < n) s += a[end];
            }
        } else {
            s -= a[start];
            ans++;
            // debug (start); debug (end);
            start++;
            if (end < start) {
                end++;
                if (end < n) s += a[end];
            }
        }
    }
    printf("%lld\n", ans);
}
