#include<cstdio>
#include<algorithm>

using namespace std;

int n, d, a, b;
int bb[1<<17], bp[1<<17], pb[1<<17], pp[1<<17], SIZE=(1<<16);

void update(int node)
{
    int l=node*2, r=node*2+1;
    pp[node] = max(pb[l]+pp[r], pp[l]+bp[r]);
    pb[node] = max(pb[l]+pb[r], pp[l]+bb[r]);
    bp[node] = max(bb[l]+pp[r], bp[l]+bp[r]);
    bb[node] = max(bb[l]+pb[r], bp[l]+bb[r]);
}

main() {
    scanf("%d %d", &n, &d);
    for(int i=0;i<n;i++) scanf("%d\n", &bb[SIZE+i]);
    for(int i=SIZE-1;i>0;i--) update(i);
    long long ans=0;
    for(int i=0;i<d;i++) {
	scanf("%d %d", &a, &b); a--;
	bb[SIZE+a] = b;
	for(int j=(SIZE+a)/2;j>0;j/=2) update(j);
	ans += bb[1];
   }
   printf("%lld\n", ans);
}
