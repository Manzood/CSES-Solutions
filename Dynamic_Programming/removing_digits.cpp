#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    int n; cin >> n;
    int ans = (n % 10 > 0);
    n /= 10;
    int cur = 1;
    while (n) {
        ans += (n % 10) * cur * 2;
        n /= 10;
        cur *= 10;
    }
    printf("%d\n", ans);
}
