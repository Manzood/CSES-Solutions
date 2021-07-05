#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    vector <pair <int, int>> a(2 * n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[2*i].first);
        a[2*i].second = 0;
        scanf("%lld", &a[2*i+1].first);
        a[2*i+1].second = 1;
    }
    sort (a.begin(), a.end());
    int cnt = 0, ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i].second == 0) {
            cnt++;
        } else {
            cnt--;
        }
        ans = max (cnt, ans);
    }
    printf("%lld\n", ans);
}
