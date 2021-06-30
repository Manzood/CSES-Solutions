#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main () {
    int N, x;
    scanf("%lld%lld", &N, &x);
    vector <int> a(N);
    map <int, int> nums;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        nums[a[i]] = i;
    }
    set <int> s;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            s.insert (a[i] + a[j]);
        }
    }
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (s.count(x - a[i])) {
            int temp = x - a[i];
            for (int j = 0; j < N; j++) {
                if (j != i && nums.count (temp - a[j]) && nums[temp - a[j]] != i && nums[temp - a[j]] != j) {
                    printf("%lld %lld %lld\n", i + 1, j + 1, nums[temp - a[j]] + 1);
                    found = true;
                    break;
                }
            }
            break;
        }
    }
    if (!found) printf("IMPOSSIBLE\n");
}
