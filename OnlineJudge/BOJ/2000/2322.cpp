#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, sum;
vector<int> a, b;

int main() {
	ios_base::sync_with_stdio(false);
	int i, x;

	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> x;
		a.push_back(x); b.push_back(x);
	}

	sort(a.begin(), a.end());

	for (i = 0; i < N; i++) {
		if (a[i] != b[i]) sum += b[i];
	}

	cout << sum;
}