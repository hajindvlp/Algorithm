#include <stdio.h>
#include <queue>
using namespace std;

queue<int> Q;
int n ,m;

int main()
{
    int i, j, tmp;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        Q.push(i);

    printf("<");
    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=m-1 ; j++)
            tmp = Q.front(), Q.pop(), Q.push(tmp);
        printf("%d", Q.front());
        Q.pop();
        if(i!=n)
            printf(", ");
    }
    printf(">");
    return 0;
}
