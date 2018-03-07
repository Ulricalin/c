#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

int main() {
	set<pair<int,int> > citys;
	int x, y;
	
	for (int i = 0; i < 100; i++) {
		do {
			x = rand();
			y = rand();
		} while (citys.find(make_pair(x, y)) != citys.end());
		citys.insert(make_pair(x, y));
	}
	for (set<pair<int,int> >::iterator p = citys.begin(); p != citys.end(); p++) {
		cout << p->first << " " << p->second << endl;
	}
	return 0;
}

