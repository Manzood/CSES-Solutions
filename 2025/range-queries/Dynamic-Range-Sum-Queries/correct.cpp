#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int inf = (int)1e9 + 7;

struct segtree {  // zero based indexing
    int size;
    vector<long long> sum;
    vector<long long> m;
    vector<long long> mx;
    segtree(int n) {
        // makes size a power of two GE n
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2 * size - 1, 0);
        m.assign(2 * size - 1, inf);
        mx.assign(2 * size - 1, -inf);
    }
    void build(vector<int>& a) {
        int n = (int)a.size();
        int numzeroes = size - n;
        int counter = 0;
        for (int i = 2 * size - 2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                sum[i] = 0;
                m[i] = inf;
                mx[i] = -inf;
            } else if (n > 0) {
                sum[i] = a[--n];
                m[i] = a[n];
                mx[i] = a[n];
            } else {
                sum[i] += sum[2 * i + 1] + sum[2 * i + 2];
                m[i] = min(m[2 * i + 1], m[2 * i + 2]);
                mx[i] = max(mx[2 * i + 1], mx[2 * i + 2]);
            }
        }
    }
    void set(int i, int v) {  // setting index i to element v
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            m[x] = v;
            mx[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        m[x] = min(m[2 * x + 1], m[2 * x + 2]);
        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
    }
    long long getsum(int left, int right) {  // returns sum between indexes
                                             // [left, right - 1], inclusive
        return getsum(left, right, 0, 0, size);
    }
    long long getsum(int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return 0;
        if (lx >= left && rx <= right) return sum[x];
        int mid = (lx + rx) / 2;
        long long s1 = getsum(left, right, 2 * x + 1, lx, mid);
        long long s2 = getsum(left, right, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
    long long getmin(int left, int right) {  // returns min between indexes
                                             // [left, right - 1], inclusive
        return getmin(left, right, 0, 0, size);
    }
    long long getmin(int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return inf;
        if (lx >= left && rx <= right) return m[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmin(left, right, 2 * x + 1, lx, mid);
        long long s2 = getmin(left, right, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }
    long long getmax(int left, int right) {  // returns max between indexes
                                             // [left, right - 1], inclusive
        return getmax(left, right, 0, 0, size);
    }
    long long getmax(int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return -inf;
        if (lx >= left && rx <= right) return mx[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmax(left, right, 2 * x + 1, lx, mid);
        long long s2 = getmax(left, right, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }
};

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    segtree st(n);
    st.build(a);
    for (int query = 0; query < q; query++) {
        int type, x, y;
        scanf("%lld%lld%lld", &type, &x, &y);
        if (type == 1) {
            st.set(x - 1, y);
        } else {
            printf("%lld\n", st.getsum(x - 1, y));
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
