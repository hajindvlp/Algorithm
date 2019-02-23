#include<cstdio>
#include<unordered_map>
using namespace std;
int k, l, a[500000];
unordered_map<int, int> mp;
int main() {
    scanf("%d%d", &k, &l);
    for (int i = 0; i < l; i++) scanf("%d", a + i), mp[a[i]] = i;
    for (int i = 0; i < l&&k; i++) if (mp[a[i]] == i) printf("%08d\n", a[i]), k--;
    return 0;
}
