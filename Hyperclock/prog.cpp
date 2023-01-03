#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

#define assert_range(x,a,b) assert((a) <= (x) and (x) <= (b))

const int MAX_N = 1e6;

int res[2][MAX_N];
int sz[2] = {0, 0};
int a[30];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if (n == 1) {
        for (int i = 0; i < a[0]; ++i) {
            printf("1 1\n");
        }
        return 0;
    }

    int id = 1;
    int cur = 0;
    for (int j = 0; j < a[0]; ++j) {
        res[cur][sz[cur]++] = id;
    }
    for (int ii = 1; ii < n; ++ii) {
        cur = 1-cur;
        const int other = 1-cur;
        const int k = a[ii];
        const int last = res[other][sz[other]-1];

        id++;

        sz[cur] = 0;
        sz[other]--;

        if (k % 2 == 0) {
            for (int i = 0; i < k; ++i) {
                if (i % 2 == 0) {
                    for (int j = 0; j < sz[other]; ++j) {
                        res[cur][sz[cur]++] = res[other][j];
                    }
                } else {
                    for (int j = sz[other]-1; j >= 0; --j) {
                        res[cur][sz[cur]++] = -res[other][j];
                    }
                }
                res[cur][sz[cur]++] = id;
            }
        } else {
            for (int j = 0; j < k-1; ++j) {
                res[cur][sz[cur]++] = id;
            }

            for (int j = 0; j < sz[other]; ++j) {
                res[cur][sz[cur]++] = res[other][j];
            }

            for (int i = 1; i < k; ++i) {
                res[cur][sz[cur]++] = -id;
                if (i % 2 == 1) {
                    for (int j = sz[other]-1; j >= 1; --j) {
                        res[cur][sz[cur]++] = -res[other][j];
                    }
                } else {
                    for (int j = 1; j < sz[other]; ++j) {
                        res[cur][sz[cur]++] = res[other][j];
                    }
                }
            }
            res[cur][sz[cur]++] = last;
        }
    }
    for (int i = 0; i < sz[cur]; ++i) {
        if (res[cur][i] > 0) {
            printf("%d %d\n", res[cur][i], 1);
        } else {
            printf("%d %d\n", -res[cur][i], -1);
        }
    }

    return 0;
}
