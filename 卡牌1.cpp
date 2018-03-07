#include <iostream>
#include <queue>
#include <list>
using namespace std;
using std::string;
int main() {
	int t, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		list<int> monkey;
		for (int i = 1; i < n+1; i++) {
			monkey.push_back(i);
		}
		int count = 0;
		list<int>::iterator p = monkey.begin();
		while (monkey.size() > 1) {
			if (++count == m) {
				count = 0;
				p = monkey.erase(p);
			} else {
				p++;
			}
			if (p == monkey.end()) p = monkey.begin();
		}
		cout << *p << endl;
	}
	return 0;
}
