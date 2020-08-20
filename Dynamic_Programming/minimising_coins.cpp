#include<bits/stdc++.h>
using namespace std; 
#define debug(x) cout<<#x<<" = "<<x<<endl;
const int N = 2e6+5;
const int INF = 1e9;
 
bool ready[N];
int solve[N];
vector <int> a;
int recursive (int val) {
    if (val < 0) return INF;
    if (val == 0) return 0;
    // debug(ans);
    if (!ready[val]) {
        solve[val] = INF;
        for (int i = 0; i < a.size(); i++) {
            solve[val] = min(solve[val], recursive(val - a[i]) + 1);
        }
        ready[val] = true;
    }
    return solve[val];
}
 
int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    // recursive
    for (int i = 0; i < N; i++) {
        ready[i] = false;
    }
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a.push_back(temp);
    }
    int ans = recursive(x);
    if (ans == INF) ans = -1;
    printf("%d", ans);
}