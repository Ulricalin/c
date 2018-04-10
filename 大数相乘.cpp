#include <iostream>
using namespace std;


int main() {
    int result[100];
    for (int i = 0; i < 100; i++) {
    	result[i]=0;
	}
    string a, b;
    cin >> a >> b;
    bool flag = true;
	if (a[0] == '-') {
		if (b[0] == '-') {
			b = b.substr(1);
		} else {
			flag = false;
		}
		a = a.substr(1);
	} else {
		if (b[0] == '-') {
			b = b.substr(1);
			flag = false;
		}
	}
	//cout 
    int lena = a.length();
    int lenb = b.length();
    for (int i = 0; i < lena; i++) {
    	for (int j = 0; j < lenb; j++) {
    		result[i+j+2] += (a[i]-'0')*(b[j]-'0');
		}
	}
	int len = lena+lenb;
	for (int i = len; i > 1; i--) {
		result[i-1] += result[i]/10;
		result[i] = result[i]%10;
	}
	if (!flag) {
		cout << "-";
	}
	if (result[1] > 0) {
		cout << result[1]; 
	}
	for (int i = 2; i <= len; i++) {
		cout << result[i];
	}
    return 0;
}
