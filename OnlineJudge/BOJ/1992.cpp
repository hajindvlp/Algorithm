#include <bits/stdc++.h>
using namespace std;

int n;
char board[66][66];

void go(int x, int y, int len)
{
    char first=board[x][y];
    for(int i=x;i<x+len;++i){
        for(int j=y;j<y+len;++j){
            if(first!=board[i][j]){
                printf("(");
                go(x,y,len/2);
                go(x,y+len/2,len/2);
                go(x+len/2,y,len/2);
                go(x+len/2,y+len/2,len/2);
                printf(")");
                return;
            }
        }
    }
    printf("%c",first);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%s",board[i]);
    go(0,0,n);
}
