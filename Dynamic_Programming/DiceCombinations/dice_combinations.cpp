#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector <long long> solve(n+1);
    solve[0] = 1;
    for (int i = 1; i <= n; i++) {
        solve[i] = 0;
        for (int j = 1; j < 7; j++) {
            if (i - j >= 0) {
                solve[i] += solve[i-j];
                solve[i] %= MOD;
            }
        }
    }
    cout << solve[n] << endl;
}