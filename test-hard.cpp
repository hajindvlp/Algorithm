#include<bits/stdc++.h>
using namespace std;
int n,t;
vector<vector<int> > e;
double ans=1e9;
long long ansup, ansdown,arr[1000003],chk[1000003];
void dv(long long a, int b) {
    int i;
    for(i=2; i*i<=b; i++) {
        if(a%i==0 && b%i==0)
            a/=i,b/=i;
    }
    if(ans>(double)a/b) {
        ans=(double)a/b;
        ansup=a, ansdown=b;
    }
    return;
}
void f(long long sum, int cnt, int cur) {
    dv(sum,cnt);
    chk[cur]=1;
    for(int num : e[cur]){
        if(!chk[num]) {
            f(sum*arr[num],cnt+1,num);
        }
    }
    return;
}
int main() {
    int i,j,k,a,b;
    scanf("%d",&t);
    for(k=1; k<=t; k++) {
        ans=1e18;
        e.erase(e.begin(), e.end());
        scanf("%d",&n);
        e.resize(n+1);
        for(i=1; i<n; i++) {
            scanf("%d %d",&a,&b);
            e[a].push_back(b);
            e[b].push_back(a);
        }
        for(i=1; i<=n; i++) {
            scanf("%d",&arr[i]);
        }
        for(i=1; i<=n; i++) {
            f(arr[i],1,i);
        }
        for(i=1;i<=n;i++) e[i].clear();
        fill(&chk[1],&chk[n+1],0);
        printf("#%d %lld/%d\n",k,ansup, ansdown);
    }
    return 0;
}
