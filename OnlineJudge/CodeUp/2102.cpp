#include <stdio.h>
typedef unsigned long long int ull;

ull n;
bool is = false;

void rec(int lev, ull a)
{
	if(lev==20)
		if(a%n == 0 && !is && a!=0)
			printf("%llu", a), is = true;
	else
	{
		rec(lev+1, a*10);
		rec(lev+1, a*10+1);
	}
}

int main()
{
	scanf("%llu", &n);
	rec(0, 0);
	if(!is)
		printf("0");
}
