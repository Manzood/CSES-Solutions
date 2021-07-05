#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector <int> a(n);
    map <int, int> mp;
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mp[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (mp.count (x - a[i]) && mp[x - a[i]] != i) {
            pos1 = mp[x - a[i]];
            pos2 = i;
        }
    }
    if (pos1 == -1) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%lld %lld\n", pos1 + 1, pos2 + 1);
    }
}
