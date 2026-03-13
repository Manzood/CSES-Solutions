#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7, MOD2 = (int)1e9 + 9;
const int p = 31;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

template <typename T>
T getpow(T a, T b, T m) {
    T result = 1;
    while (b) {
        if (b % 2 == 1) result = result * a % m;
        a = a * a % m;
        b /= 2;
    }
    return result;
}

long long compute_hash(string const& s, int mod) {
    const int m = mod;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int m;
    scanf("%lld", &m);
    vector<string> a(m);
    unordered_set<int> hashes;
    set<int> l;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        l.insert((int)a[i].size());
        int h1 = compute_hash(a[i], MOD);
        int h2 = compute_hash(a[i], MOD2);
        hashes.insert((h1 << 32) + h2);
    }

    vector<int> lengths;
    for (auto x : l) lengths.push_back(x);

    int n = (int)s.size();
    vector<pair<int, int>> prefhash(n + 1, {0, 0});
    string cur;

    for (int i = 0; i < n; i++) {
        cur += s[i];
        prefhash[i + 1] = {compute_hash(cur, MOD), compute_hash(cur, MOD2)};
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    vector<int> mult1(n + 1, 0), mult2(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        mult1[i] = inv(getpow(p, i, MOD), MOD);
        mult2[i] = inv(getpow(p, i, MOD2), MOD2);
    }

    for (int i = 0; i < n; i++) {
        for (auto len : lengths) {
            if (i - len + 1 < 0) break;
            int j = i - len + 1;
            pair<int, int> fin;

            int diff = prefhash[i + 1].first - prefhash[j].first;
            if (diff < 0) diff += MOD;
            fin.first = diff * mult1[j] % MOD;

            diff = prefhash[i + 1].second - prefhash[j].second;
            if (diff < 0) diff += MOD2;
            fin.second = diff * mult2[j] % MOD2;

            int key = (fin.first << 32) + fin.second;

            if (hashes.count(key)) {
                (dp[i + 1] += dp[j]) %= MOD;
            }
        }
    }

    printf("%lld\n", dp[n]);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
