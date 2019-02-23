#include <stdio.h>

int main(){
    int n;
    char a[1000]="";
    scanf("%d %s", &n, &a[1]);
    for(int i=1;i<=n;i++){
        printf("%c", a[i]);
        if(n-i!=0 && (n-i)%3==0) printf(",");
    }
}
