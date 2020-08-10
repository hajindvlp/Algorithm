#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int t, n, m, x, r;
int main() {
    scanf("%d", &t);
    while (t--) {
        r = 0;
        queue<pair<int, int>> qu;
        priority_queue<int> pq;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            qu.push({ x,i });
            pq.push(x);
        }
        while (qu.size()) {
            int here = qu.front().first;
            int num = qu.front().second;
            qu.pop();
            if (pq.top() == here) {
                r++;
                pq.pop();
                if (num == m)break;
            }
            else qu.push({ here,num });
        }
        printf("%d\n", r);
    }
    return 0;
}
