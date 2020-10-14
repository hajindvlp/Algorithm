#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
typedef pair<int, pair<int, int> > piii;

int n, mx;
int a[405];
vector<piii> v;
vector<vector<int> > s;

int main() {
	int i, j;
	int x, y, z;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) 
		scanf("%d:%d:%d", &x, &y, &z), a[i] = x*60*100 + y*100 + z;

	for (i = 1; i < n; i++)
		for (j = i + 1; j <= n; j++) {
			v.push_back({ a[i] + a[j], {i, j} });
			s.push_back(vector<int>(n + 1));
			s[s.size() - 1][i] = s[s.size() - 1][j] = s[s.size() - 1][0] = 1;
		}
	printf("Sorting\n");
	sort(v.begin(), v.end());
	int len = v.size();
	printf("start upperbounding %d\n", len);
	for (i = 0; i < len; i++) {
		int pre = upper_bound(v.begin(), v.end(), make_pair(v[i].first - 1000, make_pair(n, n))) - v.begin();
		printf("%d \n", i - pre);
		for (j = pre; j < i; j++) {
			if (s[j][v[i].second.first] == 0 && s[j][v[i].second.second] == 0 && 
				s[j][0] + 1 > s[i][0]) {
				s[i] = s[j];
				s[i][v[i].second.first] = 1;
				s[i][v[i].second.second] = 1;
				s[i][0]++;
			}
		}
		if (s[i][0] > mx) {
			mx = s[i][0];
		}
	}

	printf("%d\n", mx);
}