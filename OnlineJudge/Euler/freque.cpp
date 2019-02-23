#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <string.h>
using namespace std;

unordered_map<int, int> a;

int main()
{
    int i, len;
    char s[1001];

    scanf("%s", &s[1]);
    len = strlen(&s[1]);
    for(i=1 ; i<=len ; i++)
        a[s[i]]++;

    sort(a.begin(), a.end());
    len = a.size();
    for(i=a.begin() ; i<=a.end() ; i++)
        printf("%d ", a+i);
    return 0;
}
