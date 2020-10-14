#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<vector<int> > d;
tuple<int, int, int, int> a[17];
int dp[1605][17];
int n, mx;
int idx[300], visit[]

int dfs(int x) {

}

int main() {
	int i, j, len;
	char s[105];

	idx['a'] = 1;
	idx['e'] = 2;
	idx['i'] = 3;
	idx['o'] = 4;
	idx['u'] = 5;

	scanf("%d", &n);
	d.resize(n+1);
	for(i=1 ; i<=n ; i++) {
		scanf("%s", &s[1]);
		len = strlen(&s[1]);
		a[i] = {idx[s[1]], idx[s[len]], i, len};
		for(j=1 ; j<i ; j++) {
			if(get<1>(a[i]) == get<2>(a[j])) d[i].push_back(j);
			if(get<2>(a[i]) == get<1>(a[j])) d[j].push_back(i);
		}
	}

	for(i=1 ; i<=n ; i++) {
		mx = max(mx, dfs(i));
	}
}