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
    int x, a, b, c;
    scanf("%lld%lld%lld%lld", &x, &a, &b, &c);

    deque<pair<int, int>> q;
    q.push_back({x, 0});
    for (int i = 1; i < k; i++) {
        x = (a * x + b) % c;

        while (!q.empty() && q.back().first >= x) {
            q.pop_back();
        }
        q.push_back({x, i});
    }

    int out = q.front().first;
    for (int i = k; i < n; i++) {
        x = (a * x + b) % c;
        while (!q.empty() && i > q.front().second + k - 1) {
            q.pop_front();
        }
        while (!q.empty() && q.back().first >= x) {
            q.pop_back();
        }
        q.push_back({x, i});

        int mi = q.front().first;
        out ^= mi;
    }

    printf("%lld\n", out);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
