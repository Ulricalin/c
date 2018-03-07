#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	string s;
	cin >> s;
	stack<char> Stack;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') Stack.push(s[i]);
		else if (s[i] == ')') {
			if (Stack.empty()) {
				Stack.push(s[i]);
				break;
			}
			if (Stack.top() != '(') {
				break;
			} else {
				Stack.pop();
			}
		}
		else if (s[i] == ']') {
			if (Stack.empty()) {
				Stack.push(s[i]);
				break;
			}
			if (Stack.top() != '[') {
				break;
			} else {
				Stack.pop();
			}
		}
		else if (s[i] == '}') {
			if (Stack.empty()) {
				Stack.push(s[i]);
				break;
			}
			if (Stack.top() != '{') {
				break;
			} else {
				Stack.pop();
			}
		}
	}
	if (Stack.empty()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	}
	return 0;
}
