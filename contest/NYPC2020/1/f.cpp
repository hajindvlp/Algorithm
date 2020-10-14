#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<pair<int, int>, int> piii;

vector < vector<piii> > v;
int a[55][55], d[55][55], s[55][55], mx;
vector<piii> ans, realAns;
int n;

void dfs(int lev, int start, int end, int sum) {
	int i, len;
	if (lev == n) {
		if (end == n && mx < sum) {
			mx = sum;
			realAns = ans;
		}
		// for (i = 0; i < n; i++) printf("( %d | %d %d | %d ), ", i+1, ans[i].first.first, ans[i].first.second, ans[i].second);
		// printf("%d\n", sum);
	}
	else {
		len = v[lev + 1].size();
		for (i = 0; i < len; i++) {
			if (!(v[lev+1][i].first.first > end || v[lev+1][i].first.second < start)) {
				ans.push_back(v[lev + 1][i]);
				dfs(lev + 1, v[lev + 1][i].first.first, v[lev + 1][i].first.second, sum + v[lev + 1][i].second);
				ans.pop_back();
			}
		}
	}
}

int main() {
	char t[55];
	int i, j, k;
	int sum, pre;

	scanf("%d", &n);
	v.resize(n + 1);
	for (i = 1; i <= n; i++) {
		scanf("%s", &t[1]);
		t[n + 1] = 'U';
		sum = 0;
		pre = 0;
		for (j = 1; j <= n+1; j++) {
			if (t[j] == 'D') sum++;
			else if (t[j] == 'U') {
				if (pre != j-1) v[i].push_back({ { pre+1, j - 1 }, sum });
				sum = 0;
				pre = j;
			}
		}
	}

	for (i = 1; i <= n; i++) {
		int len = v[i].size();
		for (j = 0; j < len; j++) {
			printf("(%d %d | %d) ", v[i][j].first.first, v[i][j].first.second, v[i][j].second);
		}
		printf("\n");
	}

	d[1][0] = v[1][0].second;
	for (i = 2; i <= n; i++) {
		int len = v[i].size();
		for (j = 0; j < len; j++) {
			int len2 = v[i - 1].size();
			for (k = 0; k < len2; k++) {
				if (!(v[i-1][k].first.first > v[i][j].first.second || 
					  v[i-1][k].first.second < v[i][j].first.first	)) {
			}
		}
		for (j = 0; j < len; j++) {

		}
	}

	printf("\n\n");
	ans.push_back(v[1][0]);
	dfs(1, v[1][0].first.first, v[1][0].first.second, v[1][0].second);
	int cur = 1;
	for (i = 0; i < n; i++) {
		int start = realAns[i].first.first, end = realAns[i].first.second;
		
		for (j = 1; j <= cur - start; j++) printf("L");
		cur = start;
		for (j = 1; j <= end - start; j++) printf("R");
		cur = end;
		if (i != n - 1) {
			int nstart = realAns[i+1].first.first, nend = realAns[i+1].first.second;
			for (j = end; j >= start; j--) {
				if (nstart <= j && j <= nend) break;
				printf("L");
			}
			cur = j;
			printf("D");
		}
	}
	printf("\n\n");
	for (i = 0; i < n; i++) printf("( %d | %d %d | %d ),\n", i + 1, realAns[i].first.first, realAns[i].first.second, realAns[i].second);
	printf("%d\n", mx);	
}