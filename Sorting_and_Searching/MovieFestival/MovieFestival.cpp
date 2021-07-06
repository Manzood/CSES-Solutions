#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }
    sort (a.begin(), a.end());
    int end = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // debug (end);
        if (a[i].first >= end) {
            cnt++;
            end = a[i].second;
        } else {
            // we can start this one instead of the current one
            if (a[i].second < end) {
                end = a[i].second;
            }
        }
    }
    printf("%lld\n", cnt);
}
