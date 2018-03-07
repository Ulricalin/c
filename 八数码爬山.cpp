#include <cmath>    
#include <queue>    
#include <cstdio>    
#include <cstring>    
#include <iostream>  
#include <algorithm> 
#include <time.h>
using namespace std;

typedef struct node    
{    
    int h; 
    int x,y;    
    int map[3][3];    

}node; 


int post[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};

int getH_1(node &a) {
	int result = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int k = a.map[i][j];
			result += abs(post[k][0]-i)+abs(post[k][0]-j);
		}
	}
	return result;
}


bool check(node &start)   
{    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (start.map[i][j] != i*3+j) {
            	return false;
            }
        }
    }
    return true;    
}   


int move[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};  

void initial(node &start) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            start.map[i][j] = i*3+j;
        }
    }
	start.x = start.y = 0;
    for (int i = 0; i < 50; i++) {  
        bool upset = false;
        while (!upset) { 
            int dir = rand() % 4;
            int x = start.x + move[dir][0];
            int y = start.y + move[dir][1];
            if (x >= 0 && x < 3 && y >= 0 && y < 3) { 
                start.map[start.x][start.y]=start.map[x][y];
                start.map[x][y] = 0;
                start.x = x;
                start.y = y;
                upset = true;
            }
        }
    }
    start.h = getH_1(start);
}

//最陡上升 
bool hillClimbing(node &start) {
	node current = start;
	while (1) {
		if (check(current)) return true;
		node next[4];
		int k = -1;
		for (int i = 0; i < 4; i++) {
			next[i] = current;
    		next[i].x+=move[i][0];    
            next[i].y+=move[i][1];
            if(next[i].x<0||next[i].y<0||next[i].x>2||next[i].y>2) continue;    
            next[i].map[current.x][current.y]=current.map[next[i].x][next[i].y];
            next[i].map[next[i].x][next[i].y]=0;
            next[i].h=getH_1(next[i]);
            if (next[i].h < current.h) {
            	k = i;
            }
        }
        if (k == -1) {
        	return false;
        } else {
        	current = next[k];
        }
	}
}
//首选爬山 
bool firstClimbing(node &start) {
	node current = start;
	while (1) {
		if (check(current)) return true;
		node next;
		bool visited[4];
		for (int i = 0; i < 4; i++) visited[i] = false;
		int count = 0;
		int k = -1;
		while (k == -1) {
			if (count >= 4) break;
			int des = rand()%4;
			if (visited[des]) continue;
			visited[des] = true;
			count++;
			next = current;
			next.x += move[des][0];
			next.y += move[des][1];
			if(next.x<0||next.y<0||next.x>2||next.y>2) continue;
			next.map[current.x][current.y]=current.map[next.x][next.y];
            next.map[next.x][next.y]=0;
            next.h = getH_1(next);
            if (next.h < current.h) {
            	k = des;
			}
		}
        if (k == -1) {
        	return false;
        } else {
        	current = next;
        }
	}
}

//模拟退火
bool SimulatedAnnealing(node &start) {
	double temperature = 5;
	node current = start;
	while (temperature > 0.00001) {
		if (check(current)) return true;
		node next;
		int des = rand()%4;
		next = current;
		next.x += move[des][0];
		next.y += move[des][1];
		if(next.x<0||next.y<0||next.x>2||next.y>2) continue;
		next.map[current.x][current.y]=current.map[next.x][next.y];
        next.map[next.x][next.y]=0;
        next.h = getH_1(next);
        int E = next.h-current.h;
        if (E<0) {
        	current = next;
		} else if(exp((-1)*E/temperature) > ((double)(rand() % 1000) / 1000)) {
			current = next;
		}
		temperature *= 0.9999;
	}
	return false;
}

void print(node &start) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", start.map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

double HILL() {
	clock_t begin, end;
	begin= clock();
	int count = 0;
	node start;
	for (int i = 0; i < 10000; i++) {
		initial(start);
		//print(start);
		//cout << "i :" << i << endl;
		if (hillClimbing(start)) {
			count++;
		}
	}
	end = clock();
	double duration = ((double)(end - begin) / CLOCKS_PER_SEC)/10000;
	cout << "平均用时： " << duration << endl;
	return count/10000.0;
}
double FIRST() {
	clock_t begin, end;
	begin = clock();
	int count = 0;
	node start;
	for (int i = 0; i < 10000; i++) {
		initial(start);
		//print(start);
		//cout << "i :" << i << endl;
		if (firstClimbing(start)) {
			count++;
		}
	}
	end = clock();
	double duration = ((double)(end - begin) / CLOCKS_PER_SEC)/10000;
	cout << "平均用时： " << duration << endl;
	return count/10000.0;
}
double SAnnealing() {
	clock_t begin, end;
	begin = clock();
	int count = 0;
	node start;
	for (int i = 0; i < 10000; i++) {
		initial(start);
		//print(start);
		//cout << "i :" << i << endl;
		if (SimulatedAnnealing(start)) {
			count++;
		}
	}
	end = clock();
	double duration = ((double)(end - begin) / CLOCKS_PER_SEC)/10000;
	cout << "平均用时： " << duration << endl;
	return count/10000.0;
}
int main()    
{   
    cout << "最陡爬山10000次，求得成功频率： " << HILL() << endl;
    cout << "首选爬山10000次，求得成功频率： " << FIRST() << endl;
    cout << "模拟退火10000次，求得成功频率： " << SAnnealing() << endl;
	return 0;
}
