#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
	int u,v,w;
	bool operator <(edge p)const {
		return w>p.w;
	}
}a[20005];
int f[1005];

int findf(int u)
{
	return f[u]==u?u:findf(f[u]);
}

int main()
{
	int n, i, m, s, sum=0;

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		f[i]=i;

	for(i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);

	sort(a+1,a+m+1);
	f[a[1].u]=f[a[1].v]=a[1].u;
	s=a[1].w;

	for(i=2;i<=m;i++){
		int x=findf(a[i].u),y=findf(a[i].v);
		if(x!=y){
			f[x]=y;
			s+=a[i].w;
		}
	}
	for(i=1;i<=n;i++){
		f[i]=findf(f[i]);
	}

	sort(f+1,f+n+1);

	for(i=1;i<=n;i++){
		if(f[i]!=f[i-1]){
			sum++;
		}
	}
	printf("%d",sum>1?-1:s);
	return 0;
}
