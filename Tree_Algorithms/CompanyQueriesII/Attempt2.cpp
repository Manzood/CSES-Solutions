#include "bits/stdc++.h"
using namespace std;
#define int long long

constexpr int LOG = 32;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector <int> p(n, -1);
    vector <int> h(n, 0);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &p[i]);
        p[i]--;
        h[i] = h[p[i]] + 1;
    }
    vector <vector <int>> lift(n, vector <int> (LOG, -1));
    for (int i = 0; i < n; i++) lift[i][0] = p[i];
    for (int i = 0; i < n; i++) 
        for (int exp = 1; exp < LOG; exp++) 
            if (lift[i][exp - 1] != -1) lift[i][exp] = lift[lift[i][exp - 1]][exp - 1];
    for (int query = 0; query < q; query++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        a--; b--;
        if (h[a] < h[b]) swap(a, b);
        int diff = h[a] - h[b];
        for (int i = 0; (1LL << i) <= diff; i++) {
            if ((1LL << i) & diff) a = lift[a][i];
        }
        int ans = 0;
        for (int jump = LOG - 1; jump >= 0; jump--) {
            if (lift[a][jump] == -1) continue;
            if (lift[a][jump] != lift[b][jump]) {
                a = lift[a][jump];
                b = lift[b][jump];
            } else {
                ans = lift[a][jump];
            }
        }
        ans = lift[a][0];
        if (a == b) ans = a;
        printf("%lld\n", ans + 1);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}