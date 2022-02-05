#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int inf = 1e18;

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
string path;
vector <vector <bool>> visited;
vector <vector <char>> previous;
vector <vector <int>> dist;
pair <int, int> destination;
queue<pair <int, int>> q;

void bfs (int startx, int starty, vector <string>& grid) {
    q.push({startx, starty});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true;
        for (auto d: dirs) {
            int new_x = x + d[0];
            int new_y = y + d[1];
            if (ok(new_x, new_y, (int) grid.size(), (int) grid[0].size())) {
                if (!visited[new_x][new_y] && grid[new_x][new_y] != '#' && grid[new_x][new_y] != 'M') {
                    dist[new_x][new_y] = dist[x][y] + 1;
                    if (d[0] == 1 && d[1] == 0) previous[new_x][new_y] = 'D';
                    else if (d[0] == -1 && d[1] == 0) previous[new_x][new_y] = 'U';
                    else if (d[0] == 0 && d[1] == 1) previous[new_x][new_y] = 'R';
                    else previous[new_x][new_y] = 'L';
                    q.push({new_x, new_y});
                }
            } else {
                if (d[0] == 1 && d[1] == 0) path += 'D';
                else if (d[0] == -1 && d[1] == 0) path += 'U';
                else if (d[0] == 0 && d[1] == 1) path += 'R';
                else path += 'L';
                destination = {x, y};
                return;
            }
        }
        q.pop();
    }
}

vector <vector <int>> dist2;
bool possible = true;
void bfs2(int startx, int starty, vector<string>& grid, set <pair<int, int>>& path_set) {
    q.push({startx, starty});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true;
        if (path_set.count({x, y})) {
            if (dist2[x][y] <= dist[x][y]) possible = false;
            return;
        }
        for (auto d: dirs) {
            int new_x = x + d[0];
            int new_y = y + d[1];
            if (ok(new_x, new_y, (int) grid.size(), (int) grid[0].size())) {
                if (!visited[new_x][new_y] && grid[new_x][new_y] != '#') {
                    dist2[new_x][new_y] = dist2[x][y] + 1;
                    q.push({new_x, new_y});
                }
            }
        }
        q.pop();
    }
}

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <string> grid(n);
    visited.resize(n, vector <bool>(m, false));
    previous.resize(n, vector <char> (m, 'X'));
    dist.resize(n, vector <int> (m, inf));
    dist2.resize(n, vector <int> (m, inf));
    int startx, starty;
    possible = true;
    destination = {-1, -1};
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                startx = i;
                starty = j;
            }
        }
    }
    dist[startx][starty] = 0;
    bfs (startx, starty, grid);
    int x = destination.first;
    int y = destination.second;
    if (x == -1 && y == -1) possible = false;
    set <pair <int, int>> path_set;
    while (grid[x][y] != 'A') {
        path_set.insert({x, y});
        path += previous[x][y];
        if (previous[x][y] == 'L') y++;
        else if (previous[x][y] == 'R') y--;
        else if (previous[x][y] == 'U') x++;
        else if (previous[x][y] == 'D') x--;
    }
    path_set.insert({x, y});
    for (int i = 0; i < n && possible; i++) {
        for (int j = 0; j < m && possible; j++) {
            if (grid[i][j] == 'M') {
                visited[i].assign(m, false);
                dist2[i][j] = 0;
                while (!q.empty()) q.pop();
                bfs2(i, j, grid, path_set);
            }
        }
    }
    printf(possible ? "YES\n" : "NO\n");
    if (possible) {
        reverse(path.begin(), path.end());
        path.pop_back();
        printf("%lld\n", (int) path.size());
        cout << path << "\n";
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
