#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <pair <int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok (int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int32_t main () {
    string s;
    cin >> s;
    int dp[7][7][49];
    int dp_copy[7][7][49];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 49; k++) {
                dp[i][j][k] = 0;
                dp_copy[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    dp_copy[0][0][0] = 1;
    int n = 7, m = 7;
    for (int t = 1; t < 49; t++) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                char c = s[t-1];
                bool changed = false;
                if (c == 'D' || c == '?') {
                    if (ok (i - 1, j, n, m)) {
                        dp[i][j][t] += dp_copy[i-1][j][t-1];
                        changed = true;
                    }
                }
                if (c == 'U' || c == '?') {
                    if (ok (i + 1, j, n, m)) {
                        dp[i][j][t] += dp_copy[i+1][j][t-1];
                        changed = true;
                    }
                }
                if (c == 'L' || c == '?') {
                    if (ok (i, j + 1, n, m)) {
                        dp[i][j][t] += dp_copy[i][j+1][t-1];
                        changed = true;
                    }
                }
                if (c == 'R' || c == '?') {
                    if (ok (i, j-1, n, m)) {
                        dp[i][j][t] += dp_copy[i][j-1][t-1];
                        changed = true;
                    }
                }
                if (!changed) {
                    dp[i][j][t] = 0;
                }
            }
        }
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 49; k++) {
                    dp_copy[i][j][k] = dp[i][j][k];
                }
            }
        }
    }
    printf("%lld\n", dp[6][0][48]);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%lld ", dp[i][j][24]);
        }
        printf("\n");
    }
}
