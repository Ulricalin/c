#include <iostream>
#include <queue>
#include <iterator>
using namespace std;
bool istop(const queue<pair<int, int> > & que) {
	int a = (que.front()).first;
	for (queue<pair<int, int> >::iterator  p = que.begin(); p != que.end(); p++) {
		if (a < p->first) return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int m, my;
		cin >> m >> my;
		queue<pair<int, int> > que;
		pair<int, int> e;
		for (int i = 0; i < m; i++) {
			cin >> e.first;
			e.second = i;
			que.push_back(e);
		}
		int totaltime = 0;
		while (1) {
			if (istop(que)) {
				totaltime++;
				if (que.front().second == my) break;
				que.pop_front();
			} else {
				e = que.front();
				que.pop_front();
				que.push_back(e);
			}
		}
		cout << totaltime << endl;
	}
	return 0;
}
