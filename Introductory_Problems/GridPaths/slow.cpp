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

bool is_wall_split(int x, int y, int n, int m, vector<int>& direction) {
    bool retval = false;
    int newX = x + direction[0];
    int newY = y + direction[1];
    if (ok(newX, newY, n, m)) return false;
    if (x == 0 || y == 0 || x == n - 1 || y == n - 1) {
        // check all four surrounding directions
        int cnt = 0;
        for (auto d : dirs) {
            if (ok(x + d[0], y + d[1], n, m)) {
                cnt++;
            }
        }
        if (cnt == 2) return true;
    }
    return retval;
}

int findPaths(int x, int y, string& s, int index, vector<int>& direction) {
    int retval = 0;
    if (index == 48) return x == 6 && y == 0;
    if (x == 6 && y == 0) return 0;
    if (is_wall_split(x, y, 7, 7, direction)) return 0;
    if ((abs(x - 6) + abs(y)) > (48 - index)) return 0;
    visited[x][y] = true;
    if (s[index] == '?') {
        for (auto dir : dirs) {
            int newX = x + dir[0], newY = y + dir[1];
            if (ok(newX, newY, 7, 7))
                retval += findPaths(newX, newY, s, index + 1, dir);
        }
    } else {
        vector<int> d = getdir[s[index]];
        int newX = x + d[0];
        int newY = y + d[1];
        if (ok(newX, newY, 7, 7)) {
            retval += findPaths(newX, newY, s, index + 1, d);
        }
    }
    visited[x][y] = false;
    // debug(x, y, index);
    return retval;
}

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    visited = vector<vector<bool>>(7, vector<bool>(7, false));
    int ans = findPaths(0, 0, s, 0, dirs[0]);  // arbitray starting direction
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
