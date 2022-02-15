#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int MAX_N = (int)1e6 + 1;

vector<int> number_of_divisors(MAX_N, 2LL);
void precompute() {
    number_of_divisors[1]--;
    for (int i = 2; i <= 1000; i++) {
        number_of_divisors[i]--;
        for (int j = i; j < MAX_N; j += i) {
            number_of_divisors[j]++;
            if (j / i > 1000) number_of_divisors[j]++;
            // if (j == 923549) debug(i, j / i);
        }
    }
    // debug(number_of_divisors);
}

void solve([[maybe_unused]] int test) {
    int x;
    scanf("%lld", &x);
    printf("%lld\n", number_of_divisors[x]);
}

int32_t main() {
    precompute();
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
