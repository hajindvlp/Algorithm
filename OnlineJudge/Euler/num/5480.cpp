#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

stack<int> S;
vector<int> a, d;
int n;

int main()
{
    int i;
    int x;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &x), a.push_back(x);
    d.resize(n);

    for(i=0 ; i<n ; i++)
    {
        if(S.empty())
            S.push(i);
        else
        {
            while(!S.empty() || a[S.top()]<=a[i])
            {
                if(a[S.top()] == a[i])
                    d[i]++;
                else
                {
                    d[i]++;
                    S.pop();
                }
            }
            S.push(i);
        }
    }

    for(i=0 ; i<n ; i++)
        printf("%d ", d[i]);
    return 0;
}
