#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> VI;
vector<int> v, tmp;

int main(){
    int n;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &x), v.push_back(x);

    tmp.push_back(v[0]);
    for(i=1 ; i<=n ; i++)
    {
        int here = num[i];
        auto index = lower_bound(seq.begin(), seq.end(), here);

        if( index == seq.end() ) seq.push_back(here);
        else if( index < seq.end() )  *index = here;
    }

    printf("%d", seq.size());

    return 0;
}
