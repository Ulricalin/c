#include <cmath>        
#include <cstdio>    
#include <cstring>    
#include <iostream>  
#include <algorithm>
#include <time.h> 
using namespace std;

#define Nqueen 8

bool map[Nqueen][Nqueen];
int queen[Nqueen];
int H_queen[Nqueen][Nqueen];
//çš‡ååªèƒ½ç«–ç€èµ°
void initial() {
	for (int i = 0; i < Nqueen; i++) {
		for (int j = 0; j < Nqueen; j++) {
			map[i][j] = false;
		}
	}
	for (int i =  0; i < Nqueen; i++) {
		queen[i] = rand()%Nqueen;
		map[queen[i]][i] = true;
	}
}

void print() {
	for (int i = 0; i < Nqueen; i++) {
		for (int j = 0; j < Nqueen; j++) {
			cout << map[i][j] << " ";
		}
		printf("\n");
	}
	printf("\n");
}

int get_H_i(int i) {
	int count = 0;
	int col = queen[i];
	//æ¨ªå‘
	for (int j = 0; j < Nqueen; j++) {
		if (j == i) continue;
		if (map[col][j]) count++;
	}
	//å·¦ä¸Š
	for (int j = i-1, k = 1; j >= 0; j--) {
		if (col-k < 0) break;
		if (map[col-k][j]) count++;
		k++;
	}
	//å·¦ä¸‹
	for (int j = i-1, k = 1; j >= 0; j--) {
		if (col+k > Nqueen) break;
		if (map[col+k][j]) count++;
		k++;
	}
	//å³ä¸Š
	for (int j = i+1, k = 1; j < Nqueen; j++) {
		if (col-k < 0) break;
		if (map[col-k][j]) count++;
		k++;
	}
	//å·¦ä¸‹
	for (int j = i+1, k = 1; j < Nqueen; j++) {
		if (col+k > Nqueen) break;
		if (map[col+k][j]) count++;
		k++;
	}
	return count;
}
int get_H() {
	int count = 0;
	for (int i = 0; i < Nqueen; i++) {
		count += get_H_i(i);
	}
	return count>>1;
}
//æœ€é™¡çˆ¬å±±
bool hillClimbing() {
	int t = 100;
	while (t--) {
		//print();
		int queen_num = -1;
		int largestConflict = 0;

		for (int i = 0; i < Nqueen; i++) {
			int h = get_H_i(i);
			if (h > largestConflict) {
				largestConflict = h;
				queen_num = i;
			}
		}
		if (largestConflict == 0) return true;
		int queen_row = queen[queen_num];
		//cout << "row " << queen_row << "  Conflict: " << largestConflict << endl;
		int k = queen_row;
		map[queen_row][queen_num] = 0;
		for (int j = 0; j < Nqueen; j++) {
			if (j == queen_row) continue;
			queen[queen_num] = j;
			map[j][queen_num] = 1;
			int h = get_H_i(queen_num);
			//cout << "h" << j << ": "<< h << endl;
			if (h <= largestConflict) {
				largestConflict = h;
				k = j;
			}
			map[j][queen_num] = 0;
		}
		if (k == queen_row) {
			return false;
		} else {
			map[k][queen_num] = 1;
			queen[queen_num] = k;
		}
	}
	return false;
}

bool visited[Nqueen];
bool firstClimbing() {
	memset(visited,0,sizeof(visited));
	int t = 100;
	while (t--) {
		//print(); 
		if (get_H() == 0) return true;

		int queen_num = rand()%Nqueen;
		if (visited[queen_num]) continue;
		int curH = get_H_i(queen_num);
		visited[queen_num] = true;
		
		bool visited2[Nqueen];
		memset(visited2,0,sizeof(visited2));
		int queen_row = queen[queen_num];
		map[queen_row][queen_num] = false;
		
		visited2[queen_row] = true;
		int count = Nqueen-1;
		while (count > 0) {
			int row = rand()%Nqueen;
			if (visited2[row]) continue;
			count--;
			visited2[row] = true;

			queen[queen_num] = row;
			map[row][queen_num] = true;
			int h = get_H_i(queen_num);

			if (h < curH) {
				queen_row = row;
				memset(visited,0,sizeof(visited));
				break;
			} else {
				map[row][queen_num] = false;
			}
		}
		queen[queen_num] = queen_row;
		map[queen_row][queen_num] = true;
	}
	return false;
}



bool SimulatedAnnealing() {
	double temperature = 5;

	while (temperature > 0.00001) {
		if (get_H() == 0) return true;

		int queen_num = rand()%Nqueen;
		int curH = get_H_i(queen_num);

		int queen_row = queen[queen_num];
		map[queen_row][queen_num] = false;
		
		int row = rand()%Nqueen;
		queen[queen_num] = row;
		map[row][queen_num] = true;
		int E = get_H_i(queen_num)-curH;
		if (E < 0) {
			queen_row = row;
		} else if (exp((-1)*E/temperature) > ((double)(rand() % 1000) / 1000)) {
			queen_row = row;
		}
		map[row][queen_num] = false;
		queen[queen_num] = queen_row;
		map[queen_row][queen_num] = true;
		temperature *= 0.999;
	}
	return false;
}

double HILL() {
	clock_t start, end;
	start = clock();
	int count = 0;
	for (int i = 0; i < 10000; i++) {
		initial();
//		print();
//		cout << get_H() << endl;
		if (hillClimbing()) {
			count++;
		}
		//cout << endl << endl;
	}
	end = clock();
	double duration = ((double)(end - start) / CLOCKS_PER_SEC)/10000;
	cout << "Æ½¾ùÓÃÊ±£º " << duration << endl;
	return count/10000.0;
}
double FIRST() {
	clock_t start, end;
	start = clock();
	int count = 0;
	for (int i = 0; i < 10000; i++) {
		initial();
		if (firstClimbing()) {
			count++;
		}
	}
	end = clock();
	double duration = ((double)(end - start) / CLOCKS_PER_SEC)/10000;
	cout << "Æ½¾ùÓÃÊ±£º " << duration << endl;
	return count/10000.0;
}
double randomRestartHILL() {
	clock_t start, end;
	start = clock();
	int count = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 500; j++) {
			initial();
			if (hillClimbing()) {
				count++;
				break;
			}
		}
	}
	end = clock();
	double duration = ((double)(end - start) / CLOCKS_PER_SEC)/1000;
	cout << "Æ½¾ùÓÃÊ±£º " << duration << endl;
	return count/1000.0;
}
double SAnnealing() {
	clock_t start, end;
	start = clock();
	int count = 0;
	for (int i = 0; i < 10000; i++) {
		initial();
		if (SimulatedAnnealing()) {
			count++;
		}
	}
	end = clock();
	double duration = ((double)(end - start) / CLOCKS_PER_SEC)/10000;
	cout << "Æ½¾ùÓÃÊ±£º " << duration << endl;
	return count/10000.0;
}

int main()    
{   
    cout << "×î¶¸ÅÀÉ½10000´Î£¬ÇóµÃ³É¹¦ÆµÂÊ£º " << HILL() << endl;
    cout << "Ê×Ñ¡ÅÀÉ½10000´Î£¬ÇóµÃ³É¹¦ÆµÂÊ£º " << FIRST() << endl;
    cout << "Ëæ»úÖØÆô1000´Î(Éè×î¶à¿ÉÖØÆô500´Î)£¬ÇóµÃ³É¹¦ÆµÂÊ£º " << randomRestartHILL() << endl;
    cout << "Ä£ÄâÍË»ğ10000´Î£¬ÇóµÃ³É¹¦ÆµÂÊ£º " << SAnnealing() << endl;
	return 0;
}
