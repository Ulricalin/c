#include <iostream>
#include <math.h>
using namespace std;

#define MOD 987654321
#define MAX 10001

/*
这个程序实现
输入一个n
求能整除1-n的最小正整数，即最小公倍数
由于数可能比较大，输出结果mod987654321 
eg.
输入：3
输出：6 (6是能整除1，2，3的最小正整数 
 
*/ 


int main() {
	bool prime[MAX];

	//找出1-10000的质数
	for (int i = 0; i < MAX; i++) {
		prime[i] = true;
	}
	for (int i = 2; i < MAX; i++) {
		if (!prime[i]) continue;
		for (int j = i+1; j < MAX; j++) {
			if (j%i == 0) prime[j] = false;
		}
	}
	int n;
	cin >> n;

	//分解质因数，找出最大对应最大幂
	int mi[MAX];
	for (int i = 0; i <= n; i++) {
		mi[i] = 0;
	}
	int count = 0;
	for (int i = 2; i <= n; i++) {
		int k = i;
		for (int j = 2; j <= n; j++) {
			if (!prime[j]) continue;
			count = 0;
			while (k%j == 0) {
				k = k/j;
				count++;
			}
			if (count > mi[j]) mi[j] = count;
			if (k == 0) break;
		}
	}
	
	//每个质数最大幂相乘，即为最小公倍数
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		if (!prime[i]) continue;
		for (int j = 0; j < mi[i]; j++) {
			ans = (ans*i)%MOD;
		}
	}
	cout << ans << endl;
	return 0;
} 

