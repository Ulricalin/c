#include <iostream>
#include <math.h>
using namespace std;

#define MOD 987654321
#define MAX 10001

/*
�������ʵ��
����һ��n
��������1-n����С������������С������
���������ܱȽϴ�������mod987654321 
eg.
���룺3
�����6 (6��������1��2��3����С������ 
 
*/ 


int main() {
	bool prime[MAX];

	//�ҳ�1-10000������
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

	//�ֽ����������ҳ�����Ӧ�����
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
	
	//ÿ�������������ˣ���Ϊ��С������
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

