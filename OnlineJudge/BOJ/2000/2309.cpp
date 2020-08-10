#include <stdio.h>
#include <algorithm>
using namespace std;

int visit[10], a[10];
int flag;

void rec(int lev, int sum, int cnt) {
    if(flag == 0) {
        if(lev>9) {
            if(sum == 100 && cnt == 7) 
                for(int i=1 ; i<=9 ; i++)
                    if(visit[i]) {
                        printf("%d\n", a[i]);
                        flag = 1;
                    }
        }
        else {
            visit[lev] = 1;
            rec(lev+1, sum+a[lev], cnt+1);
            visit[lev] = 0;
            rec(lev+1, sum, cnt);
        }
    }
}

int main() {
    for(int i=1 ; i<=9 ; i++) scanf("%d", &a[i]);
    sort(a+1, a+10);
    rec(1, 0, 0);
}