#include <stdio.h>
#include <vector>
#define LIM 31623

vector<int> primes;
int isP[LIM+1], rmCnt, newRmCnt;
int primeCnt;
int n, startP, endP;

int main() {
    int i, j;

    scanf("%d", &n);

    for(i=2 ; i*i<=LIM ; i++) 
        if(isP[i]==0) {
            for(j=i*i ; j<=LIM ; j+=i)
                a[j] = 1;
        }

    for(i=2 ; i<=LIM ; i++) {
        if(isP[i] == 0) {
            primeCnt++;
            primes.push_back(i);            

            rmCnt = nweRmCnt;
            for(i=0 ; i<primeCnt-1 ; i++) {
                newRmCnt += (i*i) / (primes[i]*primes[i]);
            }

            if(i*i - newRmCnt <= n && n < i*i-rmCnt) {
                startP = primes[primeCnt-2];
                endP = primes[primeCnt-1];
                break;
            }
        }
    }

    printf("%d", startP*startP + )
}