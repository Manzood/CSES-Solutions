#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 7;

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map<char, vector<int>> mp = {
    {'D', {1, 0}}, {'U', {-1, 0}}, {'R', {0, 1}}, {'L', {0, -1}}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<vector<bool>> visited;
int ans = 0, calls = 0;

bool checkDirectlyInFront(vector<int>& cur, vector<int>& dir) {
    if (!ok(cur[0] + dir[0], cur[1] + dir[1], N, N) ||
        visited[cur[0] + dir[0]][cur[1] + dir[1]]) {
        int cnt = 0;
        for (auto d : dirs) {
            vector<int> newPos = {cur[0] + d[0], cur[1] + d[1]};
            if (ok(newPos[0], newPos[1], N, N) &&
                !visited[newPos[0]][newPos[1]]) {
                cnt++;
            }
            if (cnt == 3) return false;
        }
    }
    return true;
}

bool checkTouchesGridSides(vector<int>& cur) {
    // SHOULD work better???
    // WHY ISN'T THIS WORKING
    if (cur[0] == N - 1 || cur[0] == 0 || cur[1] == N - 1 || cur[1] == 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;
                int cnt = 0;
                for (auto dir : dirs) {
                    if (!ok(i + dir[0], j + dir[1], N, N) ||
                        visited[i + dir[0]][j + dir[1]]) {
                        cnt++;
                    }
                }
                if (cnt == 4) {
                    visited[cur[0]][cur[1]] = false;
                    return false;
                }
            }
        }
    }
    return true;
}

void findPaths(vector<int> cur, string& s, vector<int> dir, int length) {
    if (!ok(cur[0], cur[1], N, N)) return;
    if (visited[cur[0]][cur[1]]) return;

    if (length == N * N - 1) {
        if (cur[0] == N - 1 && cur[1] == 0) {
            ans++;
            debug(ans);
        }
        return;
    }

    // if ((abs(cur[0] - 6) + abs(cur[1]) > (48 - length))) return;
    if (cur[0] == N - 1 && cur[1] == 0) return;
    if (!checkDirectlyInFront(cur, dir)) return;
    visited[cur[0]][cur[1]] = true;
    // if (!checkTouchesGridSides(cur)) return;

    if (s[length] != '?') {
        vector<int> newDir = mp[s[length]];
        vector<int> newPos = {cur[0] + newDir[0], cur[1] + newDir[1]};
        findPaths(newPos, s, newDir, length + 1);
    } else {
        for (auto d : dirs) {
            vector<int> newPos = {cur[0] + d[0], cur[1] + d[1]};
            findPaths(newPos, s, d, length + 1);
        }
    }

    visited[cur[0]][cur[1]] = false;
}

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    visited.assign(N, vector<bool>(N, false));
    visited[0][0] = true;
    if (s[0] == '?') {
        findPaths({1, 0}, s, {1, 0}, 1);
        findPaths({0, 1}, s, {0, 1}, 1);
    } else {
        findPaths(mp[s[0]], s, mp[s[0]], 1);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
