#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <pair <int, int>> d = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

bool ok (int x, int y, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int checkgrid (int x, int y, int n) {
    int val = n * n - 1;
    for (auto temp: d) {
        if (ok (x + temp.first, y + temp.second, n)) val--;
    }
    val -= y;
    val -= (n - 1) - x;
    return val;
}

int32_t main () {
    int n;
    cin >> n;
    int ans = 0;
    int incr = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            ans += checkgrid (i, j, i + 1);
        }
        // debug (ans);
        for (int j = i - 1; j >= 0; j--) {
            ans += checkgrid (j, i, i + 1);
        }
        if (i > 1) ans += incr;
        // if (i > 0) incr += 2;
        printf("%lld\n", ans);
    }
}
