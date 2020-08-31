#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int MOD = 1e9+7;
// eventually, I will solve this problem properly

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector <int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins.begin(), coins.end());
    vector <int> dp(x+1);
    dp[0] = 1;
    vector <vector <int>> last(x+1);
    for (int i = 1; i <= x; i++) {
        dp[i] = 0;
        for (int k = 0; k < n; k++) {
            int c = coins[k];
            last[i].push_back(0);
            if (i - c > 0) {
                for (int j = 0; j < n; j++) {
                    if (coins[j] <= c) {
                        dp[i] += last[i-c][j];
                        last[i][k] += last[i-c][j];
                        dp[i] %= MOD;
                        last[i][k] %= MOD;
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                last[i][k] = 1;
            }
            // debug(i);
            // debug(k);
            // debug(coins[k]);
            // debug(last[i][k]);
        }
    }
    printf("%d\n", dp[x]);
}