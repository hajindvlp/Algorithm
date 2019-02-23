#include <stdio.h>
#include <stack>
using namespace std;

stack<int> S;
int n;

bool pro()
{
    int i, cnt, flag, len;
    int a[1001];

    len = S.size();
    for(i=1 ; i<=len ; i++)
        S.pop();
    cnt = flag = 1;

    scanf("%d", &a[1]);
    if(a[1] == 0)
        return false;
    else
        for(i=2 ; i<=n ; i++)
            scanf("%d", &a[i]);

    while(1)
    {
        if(S.empty())
            S.push(cnt), cnt++;
        else if(S.top() == a[flag])
            S.pop(), flag++;
        else if(S.top() != a[flag])
            S.push(cnt), cnt++;

        if(flag >= n)
            break;
        if(cnt>n+1)
        {
            printf("No\n");
            return true;
        }
    }
    printf("Yes\n");
    return true;
}

int main()
{
    bool k;

    scanf("%d", &n);
    while(1)
    {
        k = pro();
        if(!k)
            return 0;
    }
}
