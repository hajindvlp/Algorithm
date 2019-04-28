#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

map<pair<int, int>, int> m;
queue<pair<int, int> > Q;
int af, bf, at, bt;
int x, y, cnt;

int main()
{
    int i, j;

    scanf("%d %d %d %d", &af, &bf, &at, &bt);
    m[make_pair(0, 0)] = 1;
    Q.push(make_pair(0, 0));

    while(!Q.empty())
    {
        y = Q.front().first;
        x = Q.front().second;
        cnt = m[make_pair(y, x)];
        Q.pop();

        if(m[make_pair(af, x)] == 0 || m[make_pair(af, x)] > cnt+1) m[make_pair(af, x)] = cnt+1, Q.push(make_pair(af, x));
        if(m[make_pair(y, bf)] == 0 || m[make_pair(y, bf)] > cnt+1) m[make_pair(y, bf)] = cnt+1, Q.push(make_pair(y, bf));
        if(m[make_pair(y, 0)] == 0 || m[make_pair(y, 0)] > cnt+1) m[make_pair(y, 0)] = cnt+1, Q.push(make_pair(y, 0));
        if(m[make_pair(0, x)] == 0 || m[make_pair(0, x)] > cnt+1) m[make_pair(0, x)] = cnt+1, Q.push(make_pair(0, x));
        if(y+x<=af && (m[make_pair(y+x, 0)] == 0 || m[make_pair(y+x, 0)] > cnt+1)) m[make_pair(y+x, 0)] = cnt+1, Q.push(make_pair(y+x, 0));
        if(y+x<=bf && (m[make_pair(0, y+x)] == 0 || m[make_pair(0, y+x)] > cnt+1)) m[make_pair(0, y+x)] = cnt+1, Q.push(make_pair(0, y+x));
        if(y+x>af && (m[make_pair(af, y+x-af)] == 0 || m[make_pair(af, y+x-af)] > cnt+1)) m[make_pair(af, y+x-af)] = cnt+1, Q.push(make_pair(af, y+x-af));
        if(y+x>bf && (m[make_pair(y+x-bf, bf)] == 0 || m[make_pair(y+x-bf, bf)] > cnt+1)) m[make_pair(y+x-bf, bf)] = cnt+1, Q.push(make_pair(y+x-bf, bf));
    }
    printf("%d", m[make_pair(at, bt)]-1);
}
