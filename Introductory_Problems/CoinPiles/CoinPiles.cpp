#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        if (a < b) {
            swap (a, b);
        }
        bool ans = true;
        if (a > 2 * b) ans = false;
        int diff = a - b;
        a -= 2 * diff;
        b -= diff;
        if (a % 3 != 0) ans = false;
        printf(ans ? "YES\n" : "NO\n");
    }
}
