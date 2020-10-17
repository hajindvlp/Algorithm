#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<utility>
using namespace std;

map<int,vector<pair<int,int> > > M;
map<int,vector<pair<int,int> > >::iterator it;
vector<pair<int,int> >::iterator i;
multiset<int, greater<int> > S;

int main() {
	int N,L,a,b,h,opens,k;
	long long s=0;
    
	scanf("%d",&N);
	while(N--) {
		scanf("%d %d %d",&a,&b,&h);
		M[a].push_back(make_pair(h,1));
		M[b].push_back(make_pair(h,0));
	}
	a = 0;
	for(it=M.begin();it!=M.end();it++) {
		b = it->first;
		if(!S.empty()) s += (long long)(b - a)*(*S.begin());
		a = b;
		for(i=(it->second).begin();i!=(it->second).end();i++) {
			k= i->first;
			opens = i->second;
			if(opens) S.insert(k);
			else S.erase(S.find(k));
		}
	}
	printf("%lld\n",s);
	return 0;
}
