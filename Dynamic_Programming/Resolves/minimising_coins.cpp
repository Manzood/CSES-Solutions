#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
const int inf = 1e9+7;

int main() {
    int n, x;
    cin >> n >> x;
    vector <int> coins(n);
    vector <int> dp(x+1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    for (int i = 1; i <= x; i++) {
        dp[i] = inf;
        for (auto c : coins) {
            if (i - c >= 0) {
                dp[i] = min(dp[i-c] + 1, dp[i]);
            }
        }
    }
    if (dp[x] == inf) dp[x] = -1;
    printf("%d\n", dp[x]);
}
