#include <stdio.h>

int n, k, mn, a;
long long int d[41], ans = 1;

int main()
{
    int i;

    scanf("%d %d", &n, &k);

    d[1] = 1, d[2] = 2;
    for(i=3 ; i<=40 ; i++)
        d[i] = d[i-1]+d[i-2];

    for(i=1 ; i<=k ; i++)
        scanf("%d", &a), ans*=d[a-mn-1], mn = a;
    ans*=d[n-mn];
    printf("%lld", ans);
    return 0;
}


// #include <cstdio>
// using namespace std;
//
// long cases[41]={0,};
// long ans=1;
// void fibo(){
//     cases[0]=1;
//     cases[1]=1;
//     for(int i=2;i<=40;i++)
//         cases[i]=cases[i-2]+cases[i-1];
// }
// int main(){
//     int N,M;
//     scanf("%d%d",&N,&M);
//     fibo();
//     int a=0, b;
//     for(int i=0;i<M;i++){
//         scanf("%d",&b);
//         ans *= cases[b-a-1];
//         a=b;
//     }
//     ans*=cases[N-a];
//     printf("%ld",ans);
// }
