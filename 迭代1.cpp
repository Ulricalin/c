#include <iostream>
using namespace std;
double f(double x) {
	return x*x-2*x-1.0;
}
int main() {
	double p0 = 2.6, p1 = 2.5, p;
	for (int i = 2; i < 5; i++) {
		cout << "p" << i << " = ";
		p = p1-(f(p1)*(p1-p0)/(f(p1)-f(p0)));
		printf("%llf\n", p);
		p0 = p1;
		p1 = p;
	}
	return 0;
}
