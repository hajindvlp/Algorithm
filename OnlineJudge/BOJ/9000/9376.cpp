#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

typedef pair<int, pair<int, int> > pii;
typedef struct {
    int pp, xx, yy;
    vector<vector<int> > v;
} node;

int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

/*

구조 설계 : 큐에 구출한 죄수의 수도 저장 하면서 한번에 2명 구출 방법을 한번에 구해야 함
이해가능?
그니깐 큐에 죄수수, y, x다 넣고 d배열엔 죄수수도 고려한 구조를 짜야함

한계 : 없엔 자물쇠를 넘겨줘야함 <- 이건 어케 하노

*/
void pro() {
    queue<node> Q;
    int n, m;
    int a[105][105], d[3][105][105];
    char s[105];
    int pp, yy, xx, ty, tx, i, j, k;
    int ey, ex;

    scanf("%d %d", &n, &m);
    for(i=2 ; i<=n+1 ; i++){
        scanf("%s", &s[2]);
        for(j=2 ; j<=m+1 ; j++) {
            if(s[j] == '*') a[i][j] = -1;
            else if(s[j] == '#') a[i][j] = 1;
            else if(s[j] == '$') a[i][j] = 2, ey = i, ex = j;
        }
    }

    for(k=0 ; k<3 ; k++) for(i=1 ; i<=n+2 ; i++) for(j=1 ; j<=m+2 ; j++) d[k][i][j] = INF;
    d[0][1][1] = 0;
    Q.push({0, {1, 1}});
    while(!Q.empty()) {
        pii t = Q.front();
        pp = t.first;
        yy = t.second.first;
        xx = t.second.second;
        Q.pop();
        for(i=0 ; i<4 ; i++) {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>=1 && ty<=n+2 && tx>=1 && tx<=m+2 && a[ty][tx] != -1) {
                if(a[ty][tx] == 0 && d[pp][ty][tx] > d[pp][yy][xx]) d[pp][ty][tx] = d[pp][yy][xx], Q.push({pp, {ty, tx}});
                else if(a[ty][tx] == 1 && d[pp][ty][tx] > d[pp][yy][xx]+1) d[pp][ty][tx] = d[pp][yy][xx]+1, Q.push({pp, {ty, tx}});
                else if(a[ty][tx] == 2 && d[pp+1][ty][tx] > d[pp][yy][xx]) d[pp+1][ty][tx] = d[pp][yy][xx], Q.push({pp+1, {ty, tx}});
            }
        }
    }

    for(k=0 ; k<3 ; k++) {
        for(i=1 ; i<=n+2 ; i++) {
            for(j=1 ; j<=m+2 ; j++) {
                if(d[k][i][j] >= INF) printf("* ");
                else printf("%d ", d[k][i][j]);
            }
            printf("\n");
        }        
        printf("\n");
    }

    printf("%d\n", d[2][ey][ex]);
}

int main() {
    int T;

    scanf("%d", &T);
    while(T--) pro();
}