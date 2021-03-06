#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int MOD = 1e9+7;

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector <int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    vector <long long> dp(x+1);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        dp[i] = 0;
        for (auto c: coins) {
            if (i - c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= MOD;
            }
        }
    }
    printf("%lld\n", dp[x]);
}