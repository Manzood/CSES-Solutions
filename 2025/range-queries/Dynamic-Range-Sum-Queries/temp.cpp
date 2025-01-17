#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

class segTree {
    int _n, size;
    vector<int64_t> sum;

   public:
    segTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        _n = 2 * size - 1;
        sum.assign(_n, 0LL);
    }

    void build(vector<int>& a) {
        int n = (int)a.size(), zeroes = size - n, cur = _n - 1;
        while (cur >= _n - size) {
            if (zeroes) {
                cur--, zeroes--;
            } else {
                sum[cur] = a[cur - (_n - size)];
                cur--;
            }
        }
        for (int i = _n - 1; i > 0; i--) sum[(i - 1) / 2] += sum[i];
    }

    int64_t getSum(int node, int lx, int rx, int left, int right) {
        if (lx > right || rx < left) return 0;
        if (lx >= left && rx <= right) return sum[node];
        int64_t s =
            getSum(2 * node + 1, lx, rx - (rx - lx + 1) / 2, left, right);
        s += getSum(2 * node + 2, lx + (rx - lx + 1) / 2, rx, left, right);
        return s;
    }

    int64_t getSum(int left, int right) {
        return getSum(0, 0, size - 1, left, right - 1);
    }

    void set(int ind, int val) {
        int cur = _n / 2 + ind;
        int64_t diff = val - sum[cur];
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
        if (type == 0) {
            int val = st.getSum(x, x + 1);
            st.set(x, val + y);
        } else {
            printf("%lld\n", (long long)st.getSum(x, y));
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
