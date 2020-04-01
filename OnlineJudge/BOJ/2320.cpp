#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > d;
pair<pair<int, int>, int> a[17];
int dp[1605][17];
int n, sumn;
int idx[300];

int main() {
	int i, j, len;
	char s[105];

	scanf("%d", &n);
	d.resize(n+1);
	for(i=1 ; i<=n ; i++) {
		scanf("%s", &s[1]);
		len = strlen(&s[1]);
		a[i] = make_pair(make_pair(idx[s[1]], idx[s[len]]), len);
		for(j=1 ; j<i ; j++) {
			if(a[i].first.second == a[j].first.first) d[i].push_back(j);
			if(a[i].first.first == a[j].first.second) d[j].push_back(i);
		}
		sumn+=len;
	}

	for(i=0 ; i<=len ; i++) {
		
	}
}