#include <stdio.h>
#include <vector>
using namespace std;

vector<int> vans;
int ans = 0;
int n, m;

int main()
{

    scanf("%d", &m);
	n = m;

	while (n){
        vector<int> series;
		series.push_back(m);
		series.push_back(n);
		int num = m - n;
		while (num >= 0){
			series.push_back(num);
			num = series[series.size() - 2] - series[series.size() - 1];
		}
		if (ans < series.size()){
			ans = series.size();
			vans = series;
		}
		n--;
	}
    printf("%d\n", ans);
	for (int i = 0; i < vans.size(); i++)
        printf("%d ", vans[i]);
}
