#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int x) {
    cout << "? " << x << endl;
    string response;
    cin >> response;
    return response == "YES";
}

void solve([[maybe_unused]] int test) {
    int low = 1, high = (int)1e9;
    while (low < high) {
        int mid = (low + high) / 2;
        int response = query(mid);
        if (response) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << "! " << high << endl;
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
