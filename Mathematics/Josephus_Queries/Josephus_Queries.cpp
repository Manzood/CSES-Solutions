#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        int cnt = 0;
        int jump = 2;
        int start = 0;
        while (cnt + (n / jump) < k) {
            cnt += n / jump;
            jump += 2;
        }
    }
}
