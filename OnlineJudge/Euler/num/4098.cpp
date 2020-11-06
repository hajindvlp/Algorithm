#include <stdio.h>
#include <stack>
using namespace std;

stack<char> S1, S2;
int n, flag, cnt;
char s[28], e[28];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf(" %c", &s[i]);
        S1.push(s[i]);
    }
    for(i=1 ; i<=n ; i++)
        scanf(" %c", &e[i]);

    flag = 1;
    while(flag != n+1)
    {
        if(!S1.empty() && S1.top() == e[flag])
            flag++, S1.pop();
        else if(!S1.empty() && S1.top() != e[flag] && S1.size() != 1 )
            S2.push(S1.top()), S1.pop();
        else if(!S2.empty() || S1.top() != e[flag])
            S1.push(S2.top()), S2.pop();
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}
