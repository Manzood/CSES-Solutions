#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        int val = 1;
        int n = max (x, y);
        val += n * (n - 1);
        if (y < x) {
            if (x % 2 == 0) {
                val += x - y;
            } else {
                val -= x - y;
            }
        } else {
            if (y % 2 == 1) {
                val += y - x;
            } else {
                val -= y - x;
            }
        }
        printf("%lld\n", val);
    }
}
