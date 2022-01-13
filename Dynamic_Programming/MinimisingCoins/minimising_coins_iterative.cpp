#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int INF = 1e9;

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector <int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    int value [x+1];
    int first[x+1];
    value[0] = 0; first[0] = 0;
    for (int i = 1; i <= x; i++) {
        value[i] = INF;
        for (int j = 0; j < n; j++) {
            // printing the first coin that appears in the sum
            if (i - coins[j] >= 0 && value[i] > value[i-coins[j]] + 1) {
                value[i] = value[i-coins[j]] + 1;
                first[i] = coins[j];
            }
        }
    }
    if (value[x] == INF) value[x] = -1;
    printf("%d\n", value[x]);
    // printing optimal solution here
    // get rid of array "first" everywhere to submit this code to CSES again
    printf("Optimal solution:\n");
    while (x > 0) {
        printf("%d ", first[x]);
        x -= first[x];
    }
}
