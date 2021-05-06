#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
const int mod = 1e9+7;
 
int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector <int> coins(n);
    vector <vector <int>> dp(x+1);
    vector <vector <int>> sum(x+1);
    // dp[sum][last] is the number of ways to reach value "sum" with "last" being the previous jump
    // second[sum][last] is the sum of all trerms less than last, really
    // in my code, I've named second as sum because I don't think stright, really
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins.begin(), coins.end());
    dp[0].resize(n);
    sum[0].resize(n);
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
        sum[0][i] = 1;
    }
    for (int i = 1; i <= x; i++) {
        dp[i].resize(n);
        sum[i].resize(n);
        for (int j = 0; j < n; j++) {
            int c = coins[j];
            dp[i][j] = 0;
            if (i - c >= 0) {
                dp[i][j] = sum[i-c][j];
                dp[i][j] %= mod;
            }
            sum[i][j] = dp[i][j];
            if (j > 0) sum[i][j] += sum[i][j-1];
            sum[i][j] %= mod;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[x][i];
        ans %= mod;
    }
    printf("%lld\n", ans);
}
