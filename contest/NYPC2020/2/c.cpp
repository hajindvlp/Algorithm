#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 2000000000
#define X first
#define Y second
using namespace std;

typedef long long int ll;

ll a, r, n;
vector<pair<int, int> > v;

int main() {
	double left, right;
	int i, j;
	int lv, rv;
	int x, y;
	ll r, l;

	scanf("%lld %lld %lld", &a, &r, &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		v.push_back({ x, y });
	}

	l = 0, r = a;
	while (l <= r) {
		ll mid = (r + l) >> 1;
		left = -INF, right = INF;
		
		for (i = 0; i < n; i++) {
			if (v[i].Y != 0) {
				double sp, ep;
				sp = (double)(mid - v[i].X) / v[i].Y;
				ep = (double)(mid + r - v[i].X) / v[i].Y;
				if(sp > ep) swap(sp, ep);
				if (left < sp) left = sp, lv = i;
				if (right > ep) right = ep, rv = i;
			}
		}

		printf("%lld %lf %d %d | %lf %d %d\n", mid, left, lv, v[lv].Y, right, rv, v[rv].Y);

		if (left > right) {
			if (v[lv].Y > 0) {
				r = mid;
			}
			else if (v[lv].Y < 0) {
				l = mid + 1;
			}
			else { 
				printf("F");
				break;
			}
		}
		else if (left <= right) {

			for (i = 0; i < n; i++) if (v[i].Y == 0) {
				if (v[i].X < mid || v[i].X > mid+r) {
					printf("F");
					return 0;
				}
			}

			printf("T");
			break;
		}
	}
}