#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

// dfs doesn't work, do a bfs

bool ok (int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
// shortest!!

bool found = false;
string shortest;
string p; // path
vector <vector <bool>> visited;
void find_path (vector <string>& grid, int x, int y, int n, int m) {
    // print only if !found
    // search right
    if (visited[x][y] || found) return;
    visited[x][y] = true;
    if (grid[x][y] == 'B') {
        if (!found) {
            // cout << "YES\n";
            // cout << p.size() << "\n";
            // cout << p << "\n";
            shortest = p;
            found = true;
        } else {
            if (p.size() < shortest.size()) shortest = p;
        }
    }
    if (ok (x, y + 1, n, m) && grid[x][y+1] != '#') {
        p += 'R';
        find_path (grid, x, y + 1, n, m);
        p.pop_back();
    }
    if (ok (x + 1, y, n, m) && grid[x+1][y] != '#') {
        p += 'D';
        find_path (grid, x + 1, y, n, m);
        p.pop_back();
    }
    if (ok (x, y - 1, n, m) && grid[x][y-1] != '#') {
        p += 'L';
        find_path (grid, x, y - 1, n, m);
        p.pop_back();
    }
    if (ok (x - 1, y, n, m) && grid[x-1][y] != '#') {
        p += 'U';
        find_path (grid, x - 1, y, n, m);
        p.pop_back();
    }
}

int32_t main () {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    visited.resize (n, vector <bool> (m, false));
    // start the search at A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                find_path (grid, i, j, n, m);
            }
        }
    }
    if (!found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << shortest.size() << "\n";
        cout << shortest << "\n";
    }
}
