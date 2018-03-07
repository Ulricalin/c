/*奇数阶幻方 by林紫勤 2016.9.2
*/
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100
int main() {
	int n;//幻方阶数
	cin >> n;
	int a[MAX][MAX];
	//initialization
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = 0;
		}
	}
	int i = 1, j = n/2+1, x = 1;
	a[i][j] = 1;//place 1 in the middle of the top row
	while (x < n*n) {
		x++;
		i--; j++;
		if (i < 1) i = n;
		if (j > n) j = 1;
		while (a[i][j] != 0) {
			i++; j--;
			if (j < 1) j = n;
			if (i > n) i = 1;
			i++;
			if (i > n) i = 1;
		}
		a[i][j] = x;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << setw(5) << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
