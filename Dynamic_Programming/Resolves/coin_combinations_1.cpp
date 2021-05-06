#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
const int mod = 1e9+7;
// my entire approach is slow, and it needs to be thought about differently.... But why?
// I'll figure this out tomorrow

int32_t main() {
    int n, x;
    cin >> n >> x;
    vector <int> coins(n);
    vector <int> dp(x+1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto c : coins) {
            if (i - c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= mod;
            }
        }
    }
    printf("%d\n", dp[x]);
}
