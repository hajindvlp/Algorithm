// 맞왜틀??
#include <stdio.h>
#include <queue>

using namespace std;

queue<int> Q;
int n, m;
int r[51][51], sector[51][51];
int sectorN, sectorNum[2505], maxSectorNum, ans;
int dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0};

int canGo(int yy, int xx, int dir) {
	if(!(r[yy][xx] & 1 << dir)) return 1;
	else return 0;
}

int main() {
	int i, j, k;
	int yy, xx, ty, tx, cnt;

	scanf("%d %d", &m, &n);
	for(i=1 ; i<=n ; i++) 
		for(j=1 ; j<=m ; j++) 
			scanf("%d", &r[i][j]);

	for(i=1 ; i<=n ; i++) 
		for(j=1 ; j<=m ; j++) 
			if(sector[i][j] == 0) {
				cnt = 0;
				sector[i][j] = ++sectorN;
				Q.push(i);
				Q.push(j);
				while(!Q.empty()) {
					yy = Q.front(), Q.pop();
					xx = Q.front(), Q.pop();
					cnt++;
					for(k=0 ; k<4 ; k++) {
						ty = yy+dy[k];
						tx = xx+dx[k];
						if(ty>0 && ty<=n && tx>0 && tx<=m && sector[ty][tx]==0 && canGo(yy, xx, k)) {
							sector[ty][tx] = sectorN;
							Q.push(ty);
							Q.push(tx);
						}
					}
				}
				sectorNum[sectorN] = cnt;
				maxSectorNum = max(maxSectorNum, cnt);
			}

	for(i=1 ; i<=n ; i++)
		for(j=1 ; j<=m ; j++)
			for(k=0 ; k<4 ; k++) {
				ty = i+dy[k];
				tx = j+dx[k];
				if(ty>0 && ty<=n && tx>0 && tx<=m && !canGo(yy, xx, k) && sector[i][j]!=sector[ty][tx]) {
					ans = max(sectorNum[sector[ty][tx]] + sectorNum[sector[i][j]], ans);
				}
			}

	printf("%d\n%d\n%d", sectorN, maxSectorNum, ans);
	return 0;
}