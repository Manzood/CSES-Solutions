#include <bits/stdc++.h>

#include "custom/debugger.h"
using namespace std;

using int64 = long long;
const int64 MOD_DP = 1000000007LL;  // result modulo

// Two hash moduli for double hashing
const int64 MOD1 = 1000000007LL;
const int64 MOD2 = 1000000009LL;
const int64 P1 = 31;
const int64 P2 = 37;

int64 modpow(int64 a, int64 e, int64 m) {
    int64 r = 1 % m;
    a %= m;
    while (e > 0) {
        if (e & 1) r = (r * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    int k;
    cin >> k;

    int n = (int)s.size();

    // Precompute p^i and inv_p^i up to n for both moduli
    vector<int64> p1_pow(n + 1), p2_pow(n + 1);
    vector<int64> inv_p1_pow(n + 1), inv_p2_pow(n + 1);

    p1_pow[0] = 1;
    p2_pow[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p1_pow[i] = (p1_pow[i - 1] * P1) % MOD1;
        p2_pow[i] = (p2_pow[i - 1] * P2) % MOD2;
    }

    int64 invP1 = modpow(P1, MOD1 - 2, MOD1);
    int64 invP2 = modpow(P2, MOD2 - 2, MOD2);
    inv_p1_pow[0] = 1;
    inv_p2_pow[0] = 1;
    for (int i = 1; i <= n; ++i) {
        inv_p1_pow[i] = (inv_p1_pow[i - 1] * invP1) % MOD1;
        inv_p2_pow[i] = (inv_p2_pow[i - 1] * invP2) % MOD2;
    }

    // Read dictionary words and store their double-hash (normalized at position
    // 0)
    unordered_set<unsigned long long> dict;
    dict.reserve(k * 2 + 10);
    for (int i = 0; i < k; ++i) {
        string w;
        cin >> w;

        // compute word hash with power starting at p^0, p^1, ...
        int64 h1 = 0, h2 = 0;
        int64 pow1 = 1, pow2 = 1;
        for (char c : w) {
            int64 val = (c - 'a' + 1);
            h1 = (h1 + val * pow1) % MOD1;
            h2 = (h2 + val * pow2) % MOD2;
            pow1 = (pow1 * P1) % MOD1;
            pow2 = (pow2 * P2) % MOD2;
        }
        unsigned long long key =
            ((unsigned long long)h1 << 32) | (unsigned long long)h2;
        dict.insert(key);
    }

    // Build prefix hashes for s (prefix i -> hash of s[0..i-1])
    vector<int64> pref1(n + 1, 0), pref2(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int64 val = (s[i] - 'a' + 1);
        pref1[i + 1] = (pref1[i] + val * p1_pow[i]) % MOD1;
        pref2[i + 1] = (pref2[i] + val * p2_pow[i]) % MOD2;
    }

    // DP
    vector<int64> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] == 0) continue;  // small optimization
        // try to extend from i -> j-1 (substring s[i..j-1])
        for (int j = i; j < n; ++j) {
            // substring s[i..j]
            int64 diff1 = pref1[j + 1] - pref1[i];
            if (diff1 < 0) diff1 += MOD1;
            int64 diff2 = pref2[j + 1] - pref2[i];
            if (diff2 < 0) diff2 += MOD2;

            // normalize to position 0 by multiplying with inv_p_pow[i]
            int64 res1 = (diff1 * inv_p1_pow[i]) % MOD1;
            int64 res2 = (diff2 * inv_p2_pow[i]) % MOD2;

            unsigned long long key =
                ((unsigned long long)res1 << 32) | (unsigned long long)res2;
            if (dict.find(key) != dict.end()) {
                dp[j + 1] += dp[i];
                if (dp[j + 1] >= MOD_DP) dp[j + 1] -= MOD_DP;
            }
        }
    }

    cout << dp[n] % MOD_DP << '\n';
    return 0;
}
