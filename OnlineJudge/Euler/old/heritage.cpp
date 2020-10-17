#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char ins[100], pres[100];
int in[100], pre[100];
pair<int, int> a[28];
int c = 1;
int n;

void tree(int lef, int rig, int root)
{
    int i;
    int v = -1;

    for(i=lef ; i<=rig ; i++)
        if(in[i] == pre[c])
        {
            v = i;
            c++;
            break;
        }

    if(a[root].first == 0 && v!=-1)
    {
        a[root].first = in[v];
        if(lef<=v-1)
            tree(lef, v-1, in[v]);
        if(rig>=v+1)
            tree(v+1, rig, in[v]);
    }
    else if(v!=-1)
    {
        a[root].second = in[v];
        if(lef<=v-1)
            tree(lef, v-1, in[v]);
        if(rig>=v+1)
            tree(v+1, rig, in[v]);

    }
}

void post(int v)
{
    if(v!=0)
    {
        post(a[v].first);
        post(a[v].second);
        printf("%c", v-1+'A');
    }
}

int main()
{
    int i;

    scanf("%s %s", &ins[1], &pres[1]);
    n = strlen(&ins[1]);

    for(i=1 ; i<=n ; i++)
        in[i] = ins[i]-'A'+1, pre[i] = pres[i]-'A'+1;

    tree(1, n, 0);
    post(pre[1]);

    return 0;
}