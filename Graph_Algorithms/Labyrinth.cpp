#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

bool is_okay (int i, int j, vector <string>& a) {
    if (i < 0 || j < 0 || i >= (int)a.size() || j >= (int)a[0].size()) {
        return false;
    }
    return true;
}

vector <pair <int, int>> pts = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector <vector <bool>> visited;
vector <char> fin;
queue <pair<int, int>> q;

bool proper_bfs (vector <string>& a) {
    if (q.empty()) return false;
    auto u = q.front();
    int i = u.first;
    int j = u.second;
    debug(i);
    debug(j);
    q.pop();
    bool retval = false;
    for (auto x: pts) {
        int x1 = i + x.first;
        int y1 = j + x.second;
        if (is_okay(x1, y1, a) && a[x1][y1] != '#' && !visited[x1][y1]) {
            visited[x1][y1] = true;
            if (x.first == 1 && x.second == 0) {
                fin.push_back('D');
            }
            if (x.first == -1 && x.second == 0) {
                fin.push_back('U');
            }
            if (x.first == 0 && x.second == 1) {
                fin.push_back('R');
            }
            if (x.first == 0 && x.second == -1) {
                fin.push_back('L');
            }
            q.push({x1, y1});
            if (a[x1][y1] == 'B') {
                return true;
            }
        }
    }
    retval |= proper_bfs(a);
    if (retval == false) fin.pop_back();
    return retval;
}

int32_t main () {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <string> a(n);
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i] = s;
        visited[i].resize(m, false);
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') {
                // ans = dfs(a, i, j);
                q.push({i, j});
                visited[i][j] = true;
                ans = proper_bfs(a);
            }
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
    printf("%lld\n", (int)fin.size());
    for (int i = (int)fin.size() - 1; i >= 0; i--) {
        printf("%c", fin[i]);
    }
    printf("\n");
}
