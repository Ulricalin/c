#include <iostream>
#include <stack>
#include <queue>
using namespace std;
/*bool should_b(const stack<int> & Stack, int e) {
	if (!Stack.empty() && e == Stack.top()-1) return true;
	else return false;
}
bool should_d(const stack<int> & Stack, int e) {
	if (!Stack.empty() && e == Stack.top()-1) return true;
	else return false;
}*/
int main() {
	int n;
	cin >> n;
	int a[1001];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 0) return 0;
	stack<int> Stack1, Stack2;
	queue<char> que;

	Stack1.push(a[0]);
	que.push('a');
	int e = 0;
	for (int i = 1; i < n; i++) {
		if (Stack1.empty() || a[i] < Stack1.top()) {
			Stack1.push(a[i]);
			que.push('a');
		}
		else if (!Stack1.empty() && e == Stack1.top()-1) {
			Stack1.pop();
			e++;
			que.push('b');
			i--;
			continue;
		}
		else if (Stack2.empty() || a[i] < Stack2.top()) {
			Stack2.push(a[i]);
			que.push('c');
		} 
		else if (!Stack2.empty() && e == Stack2.top()-1) {
			Stack1.pop();
			e++;
			que.push('d');
			i--;
			continue;
		} else {
			break;
		}
	}
	while (!Stack1.empty() && e == Stack1.top()-1) {
		Stack1.pop();
		e++;
		que.push('b');
		while (!Stack2.empty() && e == Stack2.top()-1) {
			Stack2.pop();
			e++;
			que.push('d');
		}
	}
	while (!Stack2.empty() && e == Stack2.top()-1) {
		Stack2.pop();
		e++;
		que.push('d');
		while (!Stack1.empty() && e == Stack1.top()-1) {
			Stack1.pop();
			e++;
			que.push('b');
		}
	}
	if (e == n) {
		while (!que.empty()) {
			cout << que.front();
			que.pop();
			if (!que.empty()) {
				cout << " ";
			}
		}
	} else {
		cout << "0";
	}
	return 0;
}
