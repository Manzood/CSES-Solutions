#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &x, &n);
    vector<int> a(n);
    map<int, int> d;
    map<int, int> mp;
    mp[x]++;
    d[0]++;
    d[x]++;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        d[a[i]]++;
        map<int, int>::iterator it = d.find(a[i]);
        it--;
        int prev = 0;
        if (it != d.begin()) {
            prev = it->first;
        }
        it++;
        it++;
        int next = x;
        if (it != d.begin()) {
            next = it->first;
        }
        mp[next - prev]--;
        if (mp[next - prev] == 0) {
            mp.erase(next - prev);
        }
        mp[a[i] - prev]++;
        mp[next - a[i]]++;
        auto fin = mp.rbegin();
        printf("%lld\n", fin->first);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
