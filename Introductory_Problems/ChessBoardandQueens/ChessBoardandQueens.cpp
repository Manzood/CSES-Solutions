#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool checkspot(int x, int y, vector <string>& board) {
    bool retval = true;
    retval &= board[x][y] == '.';
    for (int i = 0; i < 8; i++) {
        retval &= board[i][y] != 'q';
        retval &= board[x][i] != 'q';
    }
    for (int i = min(x, y); i > 0; i--) {
        retval &= board[x - i][y - i] != 'q';
    }
    for (int i = max(x, y) + 1; i < 8; i++) {
        int diff = i - max(x, y);
        retval &= board[x + diff][y + diff] != 'q';
    }
    int tempx = x, tempy = y;
    while (tempx >= 0 && tempy < 8) {
        retval &= board[tempx][tempy] != 'q';
        tempx--; tempy++;
    }
    tempx = x; tempy = y;
    while (tempx < 8 && tempy >= 0) {
        retval &= board[tempx][tempy] != 'q';
        tempx++; tempy--;
    }
    return retval;
}

int getans (int row, vector <string>& board) {
    if (row >= 8) return 0;
    int retval = 0;
    for (int i = 0; i < 8; i++) {
        if (checkspot(row, i, board)) {
            board[row][i] = 'q';
            retval += getans(row + 1, board);
            board[row][i] = '.';
            if (row == 7) retval++;
        }
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    vector <string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    int ans = getans(0, board);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
