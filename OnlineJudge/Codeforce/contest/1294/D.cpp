#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
 
const int N = 4E5+10;
 
int q,x;
int now=0;
int num[N]={0};
 
int main()
{
	memset(num,-1,sizeof(num));
	scanf("%d%d",&q,&x);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		n%=x;
		if(num[n]==-1) num[n]=n;
		else if(num[n]+x<N) num[n]+=x;
		while(num[now%x]>=now) now++;
		printf("%d\n",now);
	}
}