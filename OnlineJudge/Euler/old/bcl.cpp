#include <stdio.h>
#include <deque>
using namespace std;

int n;
deque<char> Q;

int main()
{
	int i;
	char x;

	scanf("%d", &n);
	for(i=1 ; i<=n ; i++)
		scanf(" %c", &x), Q.push_back(x);

    for(i=1 ; i<=n ; i++)
    {
        if(Q.front()<Q.back())
        {
            printf("%c", Q.front());
            Q.pop_front();
        }
        else
        {
            printf("%c", Q.back());
            Q.pop_back();
        }
        if(i%80 == 0)
            printf("\n");
    }
    return 0;
}
