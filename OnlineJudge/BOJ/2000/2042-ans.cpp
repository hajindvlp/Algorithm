#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector<long long> a, tree;

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    }
    else {
        return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
    }
}
void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(node * 2, start, (start + end) / 2, index, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}
long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    m += k;

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size);
    a.resize(n);

    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    init(1, 0, n - 1);
    while (m--) {
        int t1, t2;
        long long t3;
        scanf("%d %d %lld", &t1, &t2, &t3);
        if (t1 == 1) {
            t2 -= 1;
            long long diff = t3 - a[t2];
            a[t2] = t3;
            update(1, 0, n - 1, t2, diff);
        }
        else if (t1 == 2) {
            scanf("%d %d", &t2, &t3);
            printf("%lld\n", sum(1, 0, n - 1, t2 - 1, t3 - 1));
        }
    }
    return 0;
}