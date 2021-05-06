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
void dfs (vector <string>& a, int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = true;
    for (auto x: pts) {
        int x1 = i + x.first;
        int y1 = j + x.second;
        if (is_okay (x1, y1, a)) {
            if (a[x1][y1] == '.') {
                dfs (a, x1, y1);
            }
        }
    }
}

int32_t main () {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <string> a;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        a.push_back(s);
        vector <bool> temp;
        visited.push_back(temp);
        visited[i].resize(m, false);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && a[i][j] == '.') {
                cnt++;
                dfs(a, i, j);
            }
        }
    }
    printf("%lld\n", cnt);
}
