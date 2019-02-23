#include <stdio.h>

int n, m, k, t, a[200002];
int main()
{
	int cnt = 0, i;

	scanf("%d", &t);
	while(t--)
	{
        cnt = 0;
		scanf("%d %d %d", &n, &m, &k);

		for(int i=1; i<=n; i++)
            scanf("%d", &a[i]), a[i+n]=a[i];

		for(i=1; i<=n*2; i++)
            a[i]+=a[i-1];

		for(i=1; i<=n; i++)
            if(a[i+m]-a[i]<k)
                cnt++;
		printf("%d\n", n==m?(!!cnt):cnt);
	}
}
