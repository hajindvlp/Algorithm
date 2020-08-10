#include <stdio.h>
#include <deque>

using namespace std;

deque<int> Q;

int main() {
	int n, i, x;
	char t[20];

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", &t[1]);
		if (t[1] == 's') printf("%d\n", Q.size());
		else if (t[1] == 'e') printf("%d\n", Q.empty());
		else if (t[1] == 'f') {
			if (Q.empty()) printf("-1\n");
			else printf("%d\n", Q.front());
		}
		else if (t[1] == 'b') {
			if (Q.empty()) printf("-1\n");
			else printf("%d\n", Q.back());
		}
		else if (t[1] == 'p') {
			if (t[6] == 'f') scanf("%d", &x), Q.push_front(x);
			if (t[6] == 'b') scanf("%d", &x), Q.push_back(x);
			if (t[5] == 'f') {
				if (Q.empty()) printf("-1\n");
				else printf("%d\n", Q.front()), Q.pop_front();
			}
			if (t[5] == 'b') {
				if (Q.empty()) printf("-1\n");
				else printf("%d\n", Q.back()), Q.pop_back();
			}

		}
	}
}