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
    vector<int64_t> mx;

   public:
    segTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        _n = 2 * size - 1;
        mx.assign(_n, 0LL);
    }

    void build(vector<int>& a) {
        int n = (int)a.size(), zeroes = size - n, cur = _n - 1;
        while (cur >= _n - size) {
            if (zeroes) {
                cur--, zeroes--;
            } else {
                mx[cur] = a[cur - (_n - size)];
                cur--;
            }
        }
        for (int i = _n - 1; i > 0; i--) mx[(i - 1) / 2] += mx[i];
    }

    int64_t getSum(int node, int lx, int rx, int left, int right) {
        if (lx > right || rx < left) return 0;
        if (lx >= left && rx <= right) return mx[node];
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
        int64_t diff = val - mx[cur];
        while (cur > 0) {
            mx[cur] += diff;
            cur = (cur - 1) / 2;
        }
        mx[0] += diff;
    }
};

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    segTree st(n);
    vector<int> tmp(n, 1);
    st.build(tmp);

    int base = 1;
    while (base * 2 < n) base *= 2;

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int ind;
        scanf("%lld", &ind);
        ind--;

        // binary search the segment tree
        int low = 0, jump = base;
        while (jump) {
            int nxt = low + jump;
            if (nxt < n) {
                int sum = st.getSum(0, nxt);
                if (sum <= ind) {
                    low += jump;
                }
            }
            jump /= 2;
        }

        ans.push_back(a[low]);
        st.set(low, 0);
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
