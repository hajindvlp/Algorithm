#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int pro() {
    int n, sum = 1, len, i;
    vector<int> a;

    scanf("%d", &n);
    if(n == -1) return 0;

    for(i=2 ; i<=n/i ; i++) 
        if(n%i == 0) {
            sum += i;
            a.push_back(i);
            if(n/i != i && i!=1) {
                sum += n/i;
                a.push_back(n/i);
            }
        }

    if(sum == n) {
        len = a.size();
        sort(a.begin(), a.end());
        printf("%d = 1", n);
        for(i=0 ; i<len ; i++) printf(" + %d", a[i]);
    } else {
        printf("%d is NOT perfect.", n);
    }

    printf("\n");
    return 1;
}

int main() {
    while(pro());
}