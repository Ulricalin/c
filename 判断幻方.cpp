#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100
int main() {
	int n;//½×Êý
	cin >> n;
	int a[MAX][MAX];
	//initialization
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	int s = 0, t;
	for (int j = 1; j <=n; j++) s+= a[1][j];
	for (int i = 1; i <= n; i++) {
		t = 0;
		for (int j = 1; j <= n; j++) {
			t += a[i][j];
		}
		if (t != s) {
			cout << "It is no a magic square!" << endl;
			return 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		t = 0;
		for (int j = 1; j <= n; j++) {
			t += a[j][i];
		}
		if (t != s) {
			cout << "It is no a magic square!" << endl;
			return 2;
		}
	}
	t = 0;
	for (int i = 1; i <= n; i++) {
		t += a[i][i];
	}
	if (t != s) {
		cout << "It is no a magic square!" << endl;
		return 3;
	}
	t = 0;
	for (int i = 1; i <= n; i++) {
		t += a[i][n-i+1];
	}
	if (t != s) {
		cout << "It is no a magic square!" << endl;
		return 4;
	}
	cout << "It is a magic square!" << endl;
	return 0;
}
