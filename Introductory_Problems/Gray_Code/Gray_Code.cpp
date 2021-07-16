#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

string code;

void make_code (int n) {
    if (!n) {
        cout << code << "\n";
        return;
    }
    code += "0";
    make_code (n - 1);
    code.pop_back();
    code += "1";
    make_code (n - 1);
    code.pop_back();
}

int32_t main () {
    int n;
    scanf("%lld", &n);
    make_code (n);
}
