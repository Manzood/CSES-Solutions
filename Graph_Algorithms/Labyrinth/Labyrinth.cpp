#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

queue <pair <int, int>> q;
vector <vector <bool>> visited;

bool bfs (int start_i, int start_j, vector <string>& grid, vector <string>& prev) {
    int n = grid.size();
    int m = grid[0].size();
    bool found = false;
    // nonrecursive
    int i = start_i;
    int j = start_j;
    visited[i][j] = true;

    while (1) {
        if (grid[i][j] == 'B') {
            found = true;
            break;
        }
        for (auto x: dirs) {
            if (ok(i + x.first, j + x.second, n, m)) {
                if (!visited[i+x.first][j+x.second] && grid[i+x.first][j+x.second] != '#') {
                    if (x.first == 1 && x.second == 0) {
                        prev[i+x.first][j+x.second] = 'D';
                    }
                    if (x.first == -1 && x.second == 0) {
                        prev[i+x.first][j+x.second] = 'U';
                    }
                    if (x.first == 0 && x.second == 1) {
                        prev[i+x.first][j+x.second] = 'R';
                    }
                    if (x.first == 0 && x.second == -1) {
                        prev[i+x.first][j+x.second] = 'L';
                    }
                    q.push ({i + x.first, j + x.second});
                    visited[i+x.first][j+x.second] = true;
                }
            }
        }
        if (q.empty()) {
            break;
        }
        i = q.front().first;
        j = q.front().second;
        q.pop();
        // how do I get the path?
    }

    return found;
}

int32_t main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <string> grid(n);
    vector <string> prev(n);
    visited.resize(n, vector <bool> (m, false));
    int startx = -1, starty = -1;
    int endx = -1, endy = -1;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        prev[i].resize(m, '.');
        for (int j = 0; j < m; j++) {
            char c = grid[i][j];
            if (c == 'A') {
                startx = i;
                starty = j;
            } else if (c == 'B') {
                endx = i;
                endy = j;
            }
        }
    }

    bool found = bfs (startx, starty, grid, prev);
    if (!found) {
        printf("NO\n");
    } else {
        printf("YES\n");
        // find path
        int i = endx;
        int j = endy;
        string path;
        while (grid[i][j] != 'A') {
            path.push_back (prev[i][j]);
            if (prev[i][j] == 'L') {
                j++;
            } else if (prev[i][j] == 'R') {
                j--;
            } else if (prev[i][j] == 'D') {
                i--;
            } else if (prev[i][j] == 'U') {
                i++;
            }
        }
        reverse (path.begin(), path.end());
        printf("%lld\n", (int) path.size());
        cout << path << "\n";
    }
}
