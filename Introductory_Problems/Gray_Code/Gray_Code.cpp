#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

string code;

vector <string> codes;
void make_code (int n) {
    if (n == 0) return;
    int len = (int) codes.size();
    vector <string> bottom = codes;
    for (int i = 0; i < len; i++) {
        reverse(codes[i].begin(), codes[i].end());
        codes[i] += '0';
    }
    reverse(bottom.begin(), bottom.end());
    for (int i = 0; i < len; i++) {
        reverse(bottom[i].begin(), bottom[i].end());
        bottom[i] += '1';
    }
    for (int i = 0; i < len; i++) {
        codes.push_back(bottom[i]);
    }
    for (int i = 0; i < 2 * len; i++) {
        reverse(codes[i].begin(), codes[i].end());
    }
    make_code (n - 1);
}

int32_t main () {
    int n;
    scanf("%lld", &n);
    codes.push_back("0");
    codes.push_back("1");
    make_code (n - 1);
    for (int i = 0; i < (int) codes.size(); i++) {
        cout << codes[i] << "\n";
    }
}
