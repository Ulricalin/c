#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int m, x, y;
		bool flag;
		int a[100], b[100];
		cin >> m;
		int length = m, i = 0;
		while (m--) {
			cin >> a[i] >> b[i];
			i++;
		}
		cin >> m; 
		while (m--) {
			cin >> x >> y;
			flag = false;
			for (int k = 0; k < length; k++) {
				if (y == b[k]) {
					flag = true;
					a[k] += x;
					break;
				}
			}
			if (!flag) {
				a[length] = x;
				b[length] = y;
				length++;
			}
		}
		for (int j = 0; j < length-1; j++) {
			i = j;
			for (int k = j; k < length; k++) {
				if (b[i] < b[k]) i = k;
			}
			if (i != j) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
		int zero = 0;
		for (int i = 0; i < length; i++) {
			if (a[i] == 0) zero++;
		}
		cout << length-zero << endl;
		for (int i = 0; i < length; i++) {
			if (a[i] == 0) continue;
			cout << a[i] << " " << b[i] << endl;
		}
	}
	return 0;
}
