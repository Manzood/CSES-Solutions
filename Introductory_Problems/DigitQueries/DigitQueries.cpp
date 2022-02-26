#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int k;
    scanf("%lld", &k);
    k--;
    int val = 1;
    int val2 = 9;
    int cur = 0;
    int mult = 1;
    while (cur + val * val2 <= k) {
        cur += val * val2;
        val++;
        val2 *= 10;
        mult *= 10;
    }
    k -= cur;
    int number = k / val;
    int rem = k % val;
    mult += number;
    vector <int> arr;
    while (mult) {
        arr.push_back(mult % 10);
        mult /= 10;
    }
    reverse(arr.begin(), arr.end());
    printf("%lld\n", arr[rem]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
