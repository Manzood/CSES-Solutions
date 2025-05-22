#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    int n = (int)s.size();

    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'A']++;
    }

    int f = 0;
    while (f < 26 && cnt[f] == 0) f++;
    int sec = f + 1;
    while (sec < 26 && cnt[sec] == 0) sec++;

    string out;
    while (f < 26 && sec < 26) {
        out += (char)f + 'A';
        out += (char)sec + 'A';
        cnt[f]--, cnt[sec]--;
        while (f < 26 && (f == sec || cnt[f] == 0)) f++;
        while (sec < 26 && (sec == f || cnt[sec] == 0)) sec++;
    }

    debug(out);

    if (sec < 26) f = sec;

    bool possible = true;
    if (f < 26 && cnt[f]) {
        if (cnt[f] > (int)out.size() + 1) {
            possible = false;
        } else {
            string other;
            int before = cnt[f] - 1;
            for (int i = 0; i < (int)out.size() - before; i++) other += out[i];
            char tmp = (char)f + 'A';
            debug(f, tmp);
            debug(other);
            for (int i = out.size() - before; i < (int)out.size(); i++) {
                other += (char)f + 'A';
                other += out[i];
            }
            other += (char)f + 'A';
            out = other;
        }
    }

    if (!possible) {
        printf("-1\n");
    } else {
        cout << out << "\n";
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
