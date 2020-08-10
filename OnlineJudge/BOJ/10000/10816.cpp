#include <stdio.h>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;

int main() {
	int n, x;

	scanf("%d", &n);
	while (n--) scanf("%d", &x), m[x]++;
	scanf("%d", &n);
	while (n--) scanf("%d", &x), printf("%d\n", m[x]);
}