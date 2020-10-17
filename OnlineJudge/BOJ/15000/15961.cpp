#include <stdio.h>
#include <map>
using namespace std;

int n, d, k, c, mx;
int a[3005], d[3005];
map<int, int> s;

int main() {
	int i, j;
	int x;

	scanf("%d %d %d %d", &n, &d, &k, &c);
	for (i = 1; i <= n+k-1; i++) {
		if (i <= n) scanf("%d", &x);
		else x = a[i - n];
		if (i < k) a[x] = 1;
		s[x]++;
		if (i >= k) {
			s[c]++;
			s[d[i % k]]--;
			if (d[i % k] == 0) s.erase(d[i % k]);
			int size = s.size();
			mx = (mx > size) ? mx : size;
		}
		d[i % k] = x;
	}
}