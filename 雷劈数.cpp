#include <iostream>
using namespace std;
int pow(int n) {
	int s = 1;
	for (int i = 1; i <= n; i++) {
		s *= 10;
	}
	return s;
}
int main() {
	int M, x, y, n, m;
	for (M = 4; M*M < pow(8); M++) {
		int n = 0;//M*MµÄÎ»Êý-1
		while (M*M/pow(++n) > 9);
		for (m = 1; m <= n; m++) {
			x = (M*M)/pow(m);
			y = (M*M)%pow(m);
			if (x+y == M) cout << M*M << endl;
		}
	}
	return 0;
}
