#include <iostream>
#include <stack>
using namespace std;
bool islowerthan(char a, char b) {
	if (a == '/' || a == '*' || a == '%') a = 1;
	else if (a == '+' || a == '-') a = 2;
	if (b == '/' || b == '*' || b == '%') b = 1;
	else if (b == '+' || b == '-') b = 2;
	if (a >= b) return true;
	return false;
}
int main() {
	string s;
	cin >> s;
	int length = s.length();
	stack<char> Stack;
	for (int i = 0; i < length; i++) {
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) cout << s[i];
		else {
			if (Stack.empty()) Stack.push(s[i]);
			else {
				while (!Stack.empty() && islowerthan(s[i], Stack.top())) {
					cout << Stack.top();
					Stack.pop();
				}
				Stack.push(s[i]);
			}
		}
	}
	while (!Stack.empty()) {
		cout << Stack.top();
		Stack.pop();
	}
	return 0;
}
