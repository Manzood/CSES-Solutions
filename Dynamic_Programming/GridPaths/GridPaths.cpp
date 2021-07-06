#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int mod = 1e9 + 7;

int32_t main() {
    int n;
    scanf("%lld", &n);
    vector <string> a(n);
    vector <vector <int>> dp(n, vector <int> (n, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '.') {
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
            } else {
                dp[i][j] = 0;
            }
            // printf("%lld ", dp[i][j]);
            dp[i][j] %= mod;
        }
        // printf("\n");
    }
    printf("%lld\n", dp[n-1][n-1]);
}
