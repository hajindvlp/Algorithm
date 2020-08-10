#include <stdio.h>
#include <queue>
using namespace std;

int n, a[41], sum, cnt, tmp;
queue<int> Q;

int main()
{
    int i, len, j;

    scanf("%d %d", &n, &sum);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    for(i=1 ; i<=n ; i++)
    {
        len = Q.size();
        for(j=1 ; j<=len ; j++)
        {
            if(Q.front() == sum)
                cnt++;
            tmp = a[i]+Q.front();
            Q.pop();
            Q.push(tmp);
        }
        Q.push(a[i]);
    }
    printf("%d", cnt);
    return 0;
}
