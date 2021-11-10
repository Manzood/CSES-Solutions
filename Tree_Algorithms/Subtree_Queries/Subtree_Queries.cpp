#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int inf = 1e9 + 7;

int tree_loc = 0;
vector <bool> visited;

struct segtree { // ZERO BASED INDEXING
    int size;
    vector <long long> sum;
    vector <long long> m;
    vector <long long> mx;
    void init (int n) { // just making our size a power of two
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2*size-1, 0);
        m.assign(2*size-1, inf);
        mx.assign(2*size-1, -inf);
    }
    void build (vector <int>& a) {
        int n = a.size();
        int numzeroes = size-n;
        int counter = 0;
        for (int i = 2*size-2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                sum[i] = 0;
                m[i] = inf;
                mx[i] = -inf;
            }
            else if (n > 0) {
                sum[i] = a[--n];
                m[i] = a[n];
                mx[i] = a[n];
            }
            else {
                sum[i] += sum[2*i+1] + sum[2*i+2];
                m[i] = min(m[2*i+1], m[2*i+2]);
                mx[i] = max(mx[2*i+1], mx[2*i+2]);
            }
        }
    }
    void set (int i, int v) { // setting index i to element v
        set (i, v, 0, 0, size);
    }
    void set (int i, int v, int x, int lx, int rx) {
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
        return;
    }
    long long getsum (int left, int right) { // returns sum between indexes [left, right - 1], inclusive
        return getsum(left, right, 0, 0, size);
    }
    long long getsum (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return 0;
        if (lx >= left && rx <= right) return sum[x];
        int mid = (lx + rx) / 2;
        long long s1 = getsum (left, right, 2 * x + 1, lx, mid);
        long long s2 = getsum (left, right, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
    long long getmin (int left, int right) { // returns min between indexes [left, right - 1], inclusive
        return getmin(left, right, 0, 0, size);
    }
    long long getmin (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return inf;
        if (lx >= left && rx <= right) return m[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmin (left, right, 2 * x + 1, lx, mid);
        long long s2 = getmin (left, right, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }
    long long getmax (int left, int right) { // returns max between indexes [left, right - 1], inclusive
        return getmax (left, right, 0, 0, size);
    }
    long long getmax (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return -inf;
        if (lx >= left && rx <= right) return mx[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmax (left, right, 2 * x + 1, lx, mid);
        long long s2 = getmax (left, right, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }
};

void dfs (int node, vector <int>& a, vector <vector <int>>& adj, vector <int>& start, vector <int>& end, vector <int>& flattened) {
    if (visited[node]) return;
    flattened.push_back (a[node]);
    visited[node] = true;
    start[node] = tree_loc++;

    for (auto u: adj[node]) {
        dfs (u, a, adj, start, end, flattened);
    }

    end[node] = tree_loc++;
    flattened.push_back(a[node]);
}


int32_t main () {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector <int> a(n);
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // flatten the tree
    tree_loc = 0;
    visited.resize(n, false);
    visited.assign(n, false);
    vector <int> flattened, start(n), end(n);
    dfs (0, a, adj, start, end, flattened);

    // now for segtree queries
    segtree st;
    st.init((int) flattened.size());
    st.build(flattened);

    // for (int i = 0; i < (int) flattened.size(); i++) {
        // printf("%lld ", flattened[i]);
    // }
    // printf("\n");

    for (int i = 0; i < q; i++) {
        int query;
        scanf("%lld", &query);
        if (query == 1) {
            int s, x;
            scanf("%lld%lld", &s, &x);
            s--;
            int ind1 = start[s];
            int ind2 = end[s];
            st.set(ind1, x);
            st.set(ind2, x);
        } else {
            int sum = 0;
            int s;
            scanf("%lld", &s);
            s--;
            int ind1 = start[s];
            int ind2 = end[s];
            sum = st.getsum (ind1, ind2 + 1);
            printf("%lld\n", sum / 2);
        }
    }
}
