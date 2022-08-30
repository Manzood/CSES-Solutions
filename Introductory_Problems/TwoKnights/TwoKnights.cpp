#include "bits/stdc++.h"
using namespace std;
#ifdef local
#include "custom/debugger.h"
#endif
#define int long long

int32_t main () {
    int n;
    cin >> n;
    vector <int> ans(max(5LL, n + 1), 0);
    ans[2] = 6; ans[3] = 28; ans[4] = 96;
    for (int i = 5; i <= n; i++) {
        // corner pieces
        int val = i * i - 3;
        ans[i] += 4 * val;

        // corner adjacent pieces
        val = i * i - 4;
        ans[i] += 8 * val;

        // remaining outer pieces
        val = i * i - 5;
        ans[i] += 4 * (i - 4) * val;

        // inner corner
        ans[i] += 4 * val;

        // inner remaining
        val = i * i - 7;
        ans[i] += 4 * (i - 4) * val;

        // final remaining
        val = i * i - 9;
        ans[i] += (i - 4) * (i - 4) * val;

        // div by 2
        ans[i] /= 2;
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }
}
