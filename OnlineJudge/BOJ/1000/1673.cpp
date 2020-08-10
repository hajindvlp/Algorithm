#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string a, line;
	getline(cin, line);
	stringstream stream(line);
	while (!stream.eof()) {
		int n, m;
		int cnt = 0;

		stream >> n >> m;
		cnt = n;
		while (n / m > 0) {
			cnt += (n / m);
			n = (n / m) + (n % m);
		}
		printf("%d\n", cnt);
	}
}