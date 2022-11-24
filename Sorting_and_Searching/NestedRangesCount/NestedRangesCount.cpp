#include "bits/stdc++.h"
#pragma GCC optimize("O2")

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
// #define int long long

const int inf = (int)1e9 + 7;
constexpr int MX = (int)4e5 + 5;

struct segtree {  // ZERO BASED INDEXING
    int size;
    vector<int> sum;
    segtree(int n) {
        // makes size a power of two greater than n
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2 * size - 1, 0);
    }
    void build(vector<int>& a) {
        int n = (int)a.size();
        int numzeroes = size - n;
        int counter = 0;
        for (int i = 2 * size - 2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                sum[i] = 0;
            } else if (n > 0) {
                sum[i] = a[--n];
            } else {
                sum[i] += sum[2 * i + 1] + sum[2 * i + 2];
            }
        }
    }
    void set(int i, int v) {  // setting index i to element v
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        return;
    }
    int getsum(int left, int right) {  // returns sum between indexes
                                       // [left, right - 1], inclusive
        return getsum(left, right, 0, 0, size);
    }
    int getsum(int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return 0;
        if (lx >= left && rx <= right) return sum[x];
        int mid = (lx + rx) / 2;
        int s1 = getsum(left, right, 2 * x + 1, lx, mid);
        int s2 = getsum(left, right, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
};

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%d", &n);
    vector<array<int, 3>> a(n);
    vector<int> uniq;

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i][0], &a[i][1]);
        a[i][2] = i;
        uniq.push_back(a[i][0]);
        uniq.push_back(a[i][1]);
    }

    sort(uniq.begin(), uniq.end());
    uniq.resize(unique(uniq.begin(), uniq.end()) - uniq.begin());

    // compress it
    map<int, int> id;
    int idx = 0;
    for (auto x : uniq) {
        id[x] = idx++;
    }
    for (int i = 0; i < n; i++) {
        a[i][0] = id[a[i][0]];
        a[i][1] = id[a[i][1]];
    }

    vector<vector<int>> ans(n, vector<int>(2, 0));
    segtree s(MX);

    // get all ranges containing current range
    sort(a.begin(), a.end(), [](array<int, 3> i, array<int, 3> j) {
        return i[0] == j[0] ? i[1] > j[1] : i[0] < j[0];
    });
    int total = 0;
    for (int i = 0; i < n; i++) {
        int c = total - s.getsum(0, a[i][1]);
        ans[a[i][2]][1] = c;
        int cur = s.getsum(a[i][1], a[i][1] + 1);
        s.set(a[i][1], cur + 1);
        total++;
    }

    // get all the ranges within the current range
    s.sum.assign(2 * s.size - 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int c = s.getsum(0, a[i][1] + 1);
        ans[a[i][2]][0] = c;
        int cur = s.getsum(a[i][1], a[i][1] + 1);
        s.set(a[i][1], cur + 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%c", ans[i][0], " \n"[i == n - 1]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", ans[i][1], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
