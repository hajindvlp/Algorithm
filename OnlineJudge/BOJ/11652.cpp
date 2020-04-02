#include <stdio.h>
#include <algorithm>
using namespace std;

long long int a[100001];
int n, mx, cnt;
long long int ans;

int main() {
	int i;

	scanf("%d", &n);
	for(i=1 ; i<=n ; i++) scanf("%lld", &a[i]);
	sort(a+1, a+n+1);

	for(i=1 ; i<=n ; i++) {
		if(a[i] == a[i-1]) 
			cnt++;
		else 
			cnt = 1;

		if(cnt > mx) {
			mx = cnt;
			ans = a[i];
		}
	}

	printf("%lld", ans);
}