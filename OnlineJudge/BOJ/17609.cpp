#include <stdio.h>
#include <string.h>

// aabxaa
// n = 3, 4

void pro() {
    char a[100005];
    int N, i, idx;

    scanf("%s", &a[1]);
    N = strlen(&a[1]);

    idx = 0;
    for(i=1 ; i<=n/2+((n%2)?1:0) ; i++) 
        if(a[i]!=a[N-i+1]){
            idx = i;
            break;
        } 
    if(!idx) printf("0");

    for(i=1 ; i<=n/2 ; i++) {

    }
}

int main() {
    int T;

    scanf("%d", &T);
    while(T--) pro();
}