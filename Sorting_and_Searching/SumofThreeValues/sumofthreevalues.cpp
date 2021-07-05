#include "bits/stdc++.h"
using namespace std;
#define int long long
#define debug(x) cout << #x << " = " << x << endl;

int32_t main () {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].first);
        a[i].second = i;
    }
    sort (a.begin(), a.end());
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        int rem = x - a[i].first;
        int start = 0;
        int end = n - 1;
        while (start < end) {
            if (start == i) {
                start++;
                continue;
            }
            if (end == i) {
                end--;
                continue;
            }
            if (a[start].first + a[end].first > rem) {
                end--;
            } else if (a[start].first + a[end].first < rem) {
                start++;
            } else {
                found = true;
                printf("%lld %lld %lld\n", a[i].second + 1, a[start].second + 1, a[end].second + 1);
                break;
            }
        }
    }
    if (!found) {
        printf("IMPOSSIBLE\n");
    }
}
