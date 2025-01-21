#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    map<int, int> max_pq;
    map<int, int> min_pq;
    int val = (k - 1) / 2;
    for (int i = 0; i <= val; i++) {
        max_pq[a[i]]++;
    }
    for (int i = val + 1; i < k; i++) {
        int mx = (*max_pq.rbegin()).first;
        if (a[i] > mx) {
            min_pq[a[i]]++;
        } else {
            min_pq[mx]++;
            int cnt = --max_pq[mx];
            if (cnt == 0) max_pq.erase(mx);
            max_pq[a[i]]++;
        }
    }
    printf("%lld ", (*max_pq.rbegin()).first);
    for (int i = k; i < n; i++) {
        int rem = a[i - k];
        if (max_pq.count(rem)) {
            int cnt = --max_pq[rem];
            if (cnt == 0) max_pq.erase(rem);
            max_pq[a[i]]++;
        } else {
            int cnt = --min_pq[rem];
            if (cnt == 0) min_pq.erase(rem);
            min_pq[a[i]]++;
        }
        int mi = (*min_pq.begin()).first;
        int mx = (*max_pq.rbegin()).first;
        if (min_pq.size() && mx > mi) {
            int f = --max_pq[mx];
            if (f == 0) max_pq.erase(mx);
            max_pq[mi]++;
            f = --min_pq[mi];
            if (f == 0) min_pq.erase(mi);
            min_pq[mx]++;
        }
        printf("%lld ", (*max_pq.rbegin()).first);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    /*cin >> t;*/
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
