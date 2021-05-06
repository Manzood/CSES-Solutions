#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int check (int x, int y, int n) {
    if (x < 0 || y < 0 || x >= n || y >= n) return false;
    return true;
}

int main() {
    int n; cin >> n;
    vector <pair<int, int>> jumps = {{1, 2}, {-1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (auto x: jumps) {
                if (check(i+x.first, j+x.second, i)) cnt++;
                ans += i * i - cnt;
                debug(cnt);
            }
        }
        printf("%lld\n", ans);
    }
}
