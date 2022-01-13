#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
const int mod = (int)1e9 + 7;

// this works! It's also twice as fast because there aren't nearly as many
// comparisons to make, which is fun AND it uses less memory. Just an overall,
// much more elegant solution. the solution is thanks to the editorial at
// https://codeforces.com/blog/entry/70018

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(x + 1, 0);
        for (int j = 0; j <= x; j++) {
            if (i == 0 && j == 0) dp[i][j] = 1;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j - coins[i] >= 0) dp[i][j] += dp[i][j - coins[i]];
            dp[i][j] %= mod;
        }
    }
    printf("%d\n", dp[n - 1][x]);
}
