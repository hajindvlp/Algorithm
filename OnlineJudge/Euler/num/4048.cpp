#include<stdio.h>
#include<algorithm>
using namespace std;

int sol(int x){
    int temp = x;
    for (int i = 0; i < 3; i++)
    {
        x = x % 1000 * 10 + x / 1000;
        if (temp > x) temp = x;
    }
    return temp;
}

int main(){

    int b[4] = {};
    scanf("%d %d %d %d", &b[0], &b[1], &b[2], &b[3]);

    int res = sol(b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3]);
    int cnt = 0;
    for (int i = 1111; i <= res; i++)
    {
        if (sol(i) == i) cnt++;
    }
    printf("%d", cnt);

}
