#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    string s;
    cin >> s;
    map <char, int> mp;
    for (int i = 0; i < (int) s.size(); i++) {
        mp[s[i]]++;
    }
    bool possible = true;
    string ans = "";
    int cnt = 0;
    char mid = '0';
    for (auto x: mp) {
        if (x.second % 2 == 1) {
            cnt++;
            mid = x.first;
            if (cnt > 1) {
                possible = false;
                break;
            }
        } else {
            for (int i = 0; i < (x.second / 2); i++) {
                ans += x.first;
            }
        }
    }
    if (cnt && possible) {
        for (int i = 0; i < mp[mid]; i++) {
            ans += mid;
        }
    }
    for (int i = ans.size() - 1 - mp[mid]; i >= 0; i--) {
        ans += ans[i];
    }
    if (possible) cout << ans << "\n";
    else cout << "NO SOLUTION\n";
}
