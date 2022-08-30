#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<vector<bool>> visited;
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m && !visited[x][y];
}
map<char, vector<int>> getdir = {
    {'U', dirs[1]}, {'D', dirs[0]}, {'L', dirs[3]}, {'R', dirs[2]}};
int calls = 0;

// far too inefficient, I think
int findpaths(int x, int y, string& s, int step) {
    if (step == 48) return (x == 6 && y == 0);
    if (visited[6][0]) return 0;
    calls++;
    visited[x][y] = true;
    int retval = 0;
    if (s[step] == '?') {
        // try all four directions
        for (auto dir : dirs) {
            int tempx = x + dir[0], tempy = y + dir[1];
            if (ok(tempx, tempy, 7, 7))
                retval += findpaths(tempx, tempy, s, step + 1);
        }
    } else {
        auto dir = getdir[s[step]];
        int tempx = x + dir[0], tempy = y + dir[1];
        if (ok(tempx, tempy, 7, 7))
            retval += findpaths(tempx, tempy, s, step + 1);
    }
    visited[x][y] = false;
    // debug(calls, step, retval);
    return retval;
}

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    visited = vector<vector<bool>>(7, vector<bool>(7, false));
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
