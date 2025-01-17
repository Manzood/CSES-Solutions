#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

// implementing my own segment tree after a few years
class segTree {
    int _n;
    vector<int> sum;

   public:
    segTree(int n) {
        _n = 1;
        while (_n < 2 * n - 1) _n *= 2;
        sum.assign(_n, 0);
    }
    void build(vector<int>& a) {
        for (int i = _n / 2 - 1; i < _n - 1; i++) sum[i] = a[i - (_n / 2 - 1)];
        for (int i = _n - 1; i > 0; i--) sum[(i - 1) / 2] += sum[i];
    }
    int getSum(int node, int lx, int rx, int left, int right) {
        if (lx > right || rx < left) return 0;
        if (lx >= left && rx <= right) return sum[node];
        int s = getSum(2 * node + 1, lx, rx - (rx - lx + 1) / 2, left, right);
        s += getSum(2 * node + 2, lx + (rx - lx + 1) / 2, rx, left, right);
        return s;
    }
    int getSum(int left, int right) {
        return getSum(0, 0, _n / 2 - 1, left, right - 1);
    }
    void set(int ind, int val) {
        int cur = _n / 2 - 1 + ind;
        int diff = val - sum[cur];
        while (cur > 0) {
            sum[cur] += diff;
            cur = (cur - 1) / 2;
        }
        sum[0] += diff;
    }
};

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    segTree st(n);
    st.build(a);
    for (int query = 0; query < q; query++) {
        int type, x, y;
        scanf("%lld%lld%lld", &type, &x, &y);
        if (type == 1) {
            st.set(x - 1, y);
        } else {
            printf("%lld\n", st.getSum(x - 1, y));
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
