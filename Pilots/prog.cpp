// O(n)
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;

#define assert_range(x,a,b) assert((a) <= (x) and (x) <= (b))
using ll = long long;
const int INF = 1e9;

using pii = pair<int, int>;
const int MAX_N = 3e6;
int a[MAX_N];

int main() {
    int n, t;
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int res = 1;
    int i = 0;
    deque<pii> mi;
    deque<pii> ma;
    for (int j = 0; j < n; ++j) {
        while (!mi.empty() && mi.back().first >= a[j]) {
            mi.pop_back();
        }
        mi.push_back({a[j], j});

        while (!ma.empty() && ma.back().first <= a[j]) {
            ma.pop_back();
        }
        ma.push_back({a[j], j});

        while (ma[0].first - mi[0].first > t) {
            if (mi[0].second < ma[0].second) {
                i = mi[0].second+1;
                mi.pop_front();
            } else {
                i = ma[0].second+1;
                ma.pop_front();
            }
        }
        res = max(res, j-i+1);
    }
    printf("%d\n", res);
    return 0;
}
