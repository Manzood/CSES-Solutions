#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check (vector <string>& board, int cur_i, int cur_j) {
    bool retval = true;
    for (int i = 0; i < 8; i++) {
        if (i != cur_j && board[cur_i][i] == '#') retval = false;
        if (i != cur_i && board[i][cur_j] == '#') retval = false;
    }
    return retval;
}

int n_queens (vector <string>& board, int rem) {
    int retval = 0;
    if (rem == 0) return retval + 1;
    int row = 8 - rem;
    for (int j = 0; j < 8; j++) {
        if (board[row][j] != '*' && board[row][j] != '#' && check(board, row, j)) {
            board[row][j] = '#';
            debug (board);
            retval += n_queens(board, rem - 1);
            board[row][j] = '.';
        }
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    vector <string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    debug (board);
    int ans = n_queens(board, 8);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
