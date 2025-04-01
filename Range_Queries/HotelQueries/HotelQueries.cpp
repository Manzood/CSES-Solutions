#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int inf = (int)1e9 + 7;

struct segtree {
    int _n;
    vector<int> mx;
    segtree(int n) {
        _n = n;
        mx.resize(2 * n + 1);
    }
    void build(vector<int>& a) {
        for (int i = _n; i < 2 * _n + 1; i++) {
            mx[i] = a[i - _n];
        }
        for (int i = _n - 1; i >= 1; i--) {
            mx[i] = max(mx[2 * i], mx[2 * i + 1]);
        }
    }
    int get(int left, int right) {
        int a = left + _n, b = right + _n;
        int mx_found = 0;
        while (a <= b && a >= 1) {
            if (a & 1) mx_found = max(mx_found, mx[a++]);
            if (!(b & 1)) mx_found = max(mx_found, mx[b--]);
            a /= 2, b /= 2;
        }
        return mx_found;
    }
    void update(int index, int val) {
        index += _n;
        mx[index] -= val;
        index /= 2;
        while (index >= 1) {
            mx[index] = max(mx[index * 2], mx[index * 2 + 1]);
            index /= 2;
        }
    }
};

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    segtree st(n);
    st.build(a);
    for (int i = 0; i < m; i++) {
        int query;
        scanf("%lld", &query);
        int ans = n;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (st.get(low, mid) >= query) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (ans < n) st.update(ans, query);
        printf("%lld ", (ans == n ? 0LL : ans + 1));
    }
}

int32_t main() {
    int t = 1;
    /* cin >> t; */
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
