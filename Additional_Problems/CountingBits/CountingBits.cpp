#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    int shift = 0;
    int ans = 0;
    while ((1LL << shift) <= n) {
        // add 2 ** shift
        if ((1LL << shift) & n) {
            int val = 1;
            for (int j = 0; j < shift; j++) {
                val *= 2;
            }
            debug (val);
            ans += val;
            debug (ans);
        }
        shift++;
    }
    printf("%lld\n", ans);
}
