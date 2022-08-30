#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int findpaths (int x, int y, string& s, int index) {
    int retval = 0;
    // debug (index);
    if (index == 48) {
        if (x == 7 && y == 0) return 1;
        else return 0;
    }
    if (s[index] == '?') {
        s[index] = 'D';
        retval += findpaths(x, y, s, index);
        s[index] = 'U';
        retval += findpaths(x, y, s, index);
        s[index] = 'R';
        retval += findpaths(x, y, s, index);
        s[index] = 'L';
        retval += findpaths(x, y, s, index);
        s[index] = '?';
    } else if (s[index] == 'D') {
        x++;
    } else if (s[index] == 'U') {
        x--;
    } else if (s[index] == 'R') {
        y++;
    } else if (s[index] == 'L') {
        y--;
    }
    if (x < 0 || x > 7 || y < 0 || y > 7) return 0;
    retval += findpaths(x, y, s, index + 1);
    return retval;
}

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int ans = findpaths(0, 0, s, 0);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
