// O(n*log(n)) too slow to get ACC
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
    int lo = 2;
    int hi = n;
    while (lo <= hi) {
        int len = lo + (hi-lo)/2;
        deque<pii> mi;
        deque<pii> ma;
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (i >= len) {
                while (!mi.empty() && mi[0].second < i-len+1) {
                    mi.pop_front();
                }
                while (!ma.empty() && ma[0].second < i-len+1) {
                    ma.pop_front();
                }
            }
            while (!mi.empty() && mi.back().first >= a[i]) {
                mi.pop_back();
            }
            mi.push_back({a[i], i});

            while (!ma.empty() && ma.back().first <= a[i]) {
                ma.pop_back();
            }
            ma.push_back({a[i], i});

            if (i >= len-1 && ma[0].first - mi[0].first <= t) {
                found = true;
                break;
            }
        }
        if (found) {
            res = max(res, len);
            lo = len+1;
        } else {
            hi = len-1;
        }
    }
    printf("%d\n", res);
    return 0;
}
