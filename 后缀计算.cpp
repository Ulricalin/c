#include <iostream>
#include <stack> 
#include <iomanip>
using namespace std;
double op(char c, double a,double b) {
	if (c == '+') return a+b;
	else if (c == '-') return a-b;
	else if (c == '*') return a*b;
	else if (c == '/') return a/b;
}
int main() {
	int text;
	cin >> text;
	while (text--) {
		double a, b;
		string s;
		cin >> s;
		stack<double> num;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				num.push(s[i]-'a'+1);
			} else {
				b = num.top();
				num.pop();
				a = num.top();
				num.pop();
				num.push(op(s[i], a, b));
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << num.top() << endl;
	}
	return 0;
}
