#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

struct Point {
    int x, y;
};

void solve([[maybe_unused]] int test) {
    Point a, b, c;
    scanf("%lld%lld%lld%lld%lld%lld", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);

    if (b.x == a.x) {
        if (b.y > a.y) {
            if (c.x < a.x) {
                printf("LEFT\n");
            } else if (c.x == a.x) {
                printf("TOUCH\n");
            } else {
                printf("RIGHT\n");
            }
        } else {
            if (c.x < a.x) {
                printf("RIGHT\n");
            } else if (c.x == a.x) {
                printf("TOUCH\n");
            } else {
                printf("LEFT\n");
            }
        }
        return;
    }

    int ydiff = b.y - a.y;
    int xdiff = b.x - a.x;

    if (ydiff == 0) {
        if (b.x > a.x) {
            if (c.y > a.y) {
                printf("LEFT\n");
            } else if (c.y == a.y) {
                printf("TOUCH\n");
            } else {
                printf("RIGHT\n");
            }
        } else {
            if (c.y > a.y) {
                printf("RIGHT\n");
            } else if (c.y == a.y) {
                printf("TOUCH\n");
            } else {
                printf("LEFT\n");
            }
        }
        return;
    }

    int y = ydiff * c.x + a.y * xdiff - ydiff * a.x;
    bool touch = false, left = true;

    if (ydiff * xdiff > 0) {
        if (b.x > a.x) {
            if (y == c.y * xdiff) {
                touch = true;
            } else if (y < c.y * xdiff) {
                left = true;
            } else {
                left = false;
            }
        } else {
            if (y == c.y * xdiff) {
                touch = true;
            } else if (y < c.y * xdiff) {
                left = false;
            } else {
                left = true;
            }
        }
    } else {
        if (b.x > a.x) {
            if (y == c.y * xdiff) {
                touch = true;
            } else if (y < c.y * xdiff) {
                left = true;
            } else {
                left = false;
            }
        } else {
            if (y == c.y * xdiff) {
                touch = true;
            } else if (y < c.y * xdiff) {
                left = false;
            } else {
                left = true;
            }
        }
    }

    if (xdiff < 0) left ^= 1;

    if (touch) {
        printf("TOUCH\n");
    } else if (left) {
        printf("LEFT\n");
    } else {
        printf("RIGHT\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
