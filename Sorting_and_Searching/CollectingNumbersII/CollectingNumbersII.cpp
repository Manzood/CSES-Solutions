#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <int> a(n);
    vector <int> get_pos(n);
    vector <int> get_num(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        get_pos[a[i] - 1] = i;
        get_num[i] = a[i];
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (get_pos[i-1] < get_pos[i]) ans++;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x--; y--;
        int num1 = get_num[x] - 1;
        int num2 = get_num[y] - 1;
        // debug (num1, num2);
        if (num1 - 1 >= 0 && get_pos[num1] < get_pos[num1 - 1]) ans--;
        if (num1 != num2 - 1 && num2 - 1 >= 0 && get_pos[num2] < get_pos[num2 - 1]) ans--;
        if (num1 + 1 < n && get_pos[num1 + 1] < get_pos[num1]) ans--;
        if (num1 != num2 + 1 && num2 + 1 < n && get_pos[num2 + 1] < get_pos[num2]) ans--;
        // debug (ans);
        swap (a[x], a[y]);
        swap (get_num[x], get_num[y]);
        swap (get_pos[num1], get_pos[num2]);
        // debug (a, get_pos, ans, num1, num2);
        if (num1 - 1 >= 0 && get_pos[num1] < get_pos[num1 - 1]) ans++;
        if (num1 != num2 - 1 && num2 - 1 >= 0 && get_pos[num2] < get_pos[num2 - 1]) ans++;
        if (num1 + 1 < n && get_pos[num1 + 1] < get_pos[num1]) ans++;
        if (num1 != num2 + 1 && num2 + 1 < n && get_pos[num2 + 1] < get_pos[num2]) ans++;
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
