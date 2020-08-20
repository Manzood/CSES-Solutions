#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int INF = 1e9;

int ans = 0;
vector <int> coins;
int val;
// recursive, first
int solve(int x, int sum) {
    if (x < 0) return 0;
    if (sum == val) ans++;
    for (int i = 0; i < sz(coins); i++) {
        if (x - coins[i] >= 0) {
            solve(x-coins[i], sum+coins[i]);
        }
    }
    return 0;
}

int main() {
    int n, x, temp;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        coins.push_back(temp);
    }
    val = x;
    solve(x, 0);
    printf("%d\n", ans);
}