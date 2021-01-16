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
string fin = "";
bool dfs (vector <string>& a, int i, int j) {
    if (visited[i][j]) return false;
    bool ans = false;
    visited[i][j] = true;
    if (a[i][j] == 'B') {
        return true;
    }
    for (auto x: pts) {
        int x1 = i + x.first;
        int y1 = j + x.second;
        if (is_okay (x1, y1, a)) {
            bool cur = false;
            cur = dfs (a, x1, y1);
            if (ans) {
                if (x.first == 1) fin += "D";
                if (x.first == -1) fin += "U";
                if (x.second == 1) fin += "R";
                if (x.second == -1) fin += "L";
            }
            ans |= cur;
        }
    }
    return ans;
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
                ans = dfs(a, i, j);
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
