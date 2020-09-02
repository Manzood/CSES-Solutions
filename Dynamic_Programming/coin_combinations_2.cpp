#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int MOD = 1e9+7;
// I believe that the second dimension of DP is important here
// first dimension is the number, and the second is the number of ways to get that sum with that coin used at the end 
// A further observation to reduce the complexity from O(n*k*k) to O(n*k) : d[i][k] will be dp[i-1][k] + dp[i][k-1], because we are redoing certain calculations here too
// It can be classified as dp within dp, of sorts
// Perhaps this is, in fact, incorrect?
// I feel close? I really hope to figure this out
// log for 2nd Sept, I'm gonna call it quits for the moment. Memory limit exceeded, which is pretty unfortunate
// I really managed to bring the complexity down to O(n*k), but at the cost of O((x+1)*n*2+n) memory, which is unfortunate

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector <int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins.begin(), coins.end());
    vector <vector <int>> dp(x+1, vector <int> (n, 0));
    vector <vector <int>> sum(x+1, vector <int> (n, 0));
    for (int i = 0; i <= x; i++) {
        int ind = 0;
        for (auto c: coins) {
            if (i - c > 0) {
                // dp[i][ind] += dp[i-c][ind] + dp[i][ind-1];
                dp[i][ind] += sum[i-c][ind];
                if (ind > 0) {
                    sum[i][ind] = dp[i][ind] + sum[i][ind-1];
                }
                else
                    sum[i][ind] = dp[i][ind];
            }
            else if (i - c == 0) {
                dp[i][ind] = 1;
                if (ind > 0) {
                    sum[i][ind] = dp[i][ind] + sum[i][ind-1];
                }
                else {
                    sum[i][ind] = dp[i][ind];
                }
            }
            else {
                if (ind == 0) {
                    sum[i][ind] = dp[i][ind];
                }
                else {
                    sum[i][ind] = dp[i][ind] + sum[i][ind-1];
                }
            }
            ind++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[x][i];
        ans %= MOD;
    }
    printf("%d\n", ans);
}