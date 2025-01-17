// Todo: make a better generator, eventually
#include "bits/stdc++.h"
using namespace std;

constexpr int MX = (int)100000;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

// generate vector of a particular size with values between start and end,
// inclusive
vector<int> generate_vector(int start, int end, int size) {
    vector<int> temp(size);
    for (int i = 0; i < size; i++) {
        int x = rand(start, end);
        temp[i] = x;
    }
    return temp;
}

// generate a permuation of a particular size
vector<int> generate_permutation(int size) {
    vector<int> temp(size);
    for (int i = 0; i < size; i++) temp[i] = i + 1;
    random_shuffle(temp.begin(), temp.end());
    return temp;
}

// print a vector, in its entirety
void print_vector(vector<int>& v) {
    for (auto x : v) printf("%d ", x);
    printf("\n");
}

int main([[maybe_unused]] int argc, char* argv[]) {
    srand(atoi(argv[1]));
    // test cases
    // printf("1\n");
    int n = MX;
    printf("%d", n);
    // int m = rand (2, 10);
    // printf(" %d", m);
    printf("\n");
    vector<int> a = generate_vector(0, 1000, n);
    print_vector(a);
    int q = MX;
    printf("%d\n", q);
    for (int i = 0; i < q; i++) {
        int type = rand(1, 2);
        if (type == 1) {
            int x = rand(1, n);
            int y = rand(0, 1000);
            printf("%d %d %d\n", type, x, y);
        } else {
            int x = rand(1, n);
            int y = rand(x, n);
            printf("%d %d %d\n", type, x, y);
        }
    }
}
