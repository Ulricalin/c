#include <cmath>    
#include <queue>    
#include <cstdio>    
#include <cstring>    
#include <iostream>  
#include <algorithm> 
using namespace std;

typedef struct node    
{    
    int f,h,g;    
    int x,y;    
    char map[3][3];    
    friend bool operator<(const node &a,const node &b)    
    {    
        if(a.f==b.f) return a.g<b.g;    
        return a.f>b.f;    
    }    
}node; 

int Hash[15];

int Cantor(node &a) {
	int result = 0;
	int s[10]; 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			s[3*i+j] = a.map[i][j];
			int n_large = 0;
			for(int k=3*i+j-1;k>=0;k--)
            {    
                if(s[k]>s[3*i+j]) n_large++;    
            }
            result += Hash[3*i+j]*n_large;
		}
	}
	return result;
}

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

int getH_2(node &a) {
	int result = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a.map[i][j] != 3*i+j) result++;
		}
	}
	return result;
}

bool check(node &start)   
{    
    int i,j,k;    
    int s[20];    
    int cnt=0;    
    for(i=0;i<3;i++)    
    {    
        for(j=0;j<3;j++)    
        {    
            s[3*i+j]=start.map[i][j];    
            if(s[3*i+j]==0) continue;    
            for(k=3*i+j-1;k>=0;k--)    
            {    
                if(s[k]==0) continue;    
                if(s[k]>s[3*i+j]) cnt++;    
            }    
        }    
    }    
    if(cnt%2) return false;    
    return true;    
}   

bool visited[500000];
int move[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};  
int search(node &start) {
	memset(visited,0,sizeof(visited));

	priority_queue<node> Q;

    start.g=0;
    //start.h=getH_1(start); 
    start.h=getH_2(start); 
    start.f=start.h;


    Q.push(start);

    node next;
    while(!Q.empty()) {
    	node a = Q.top();
    	Q.pop();

    	int state_num = Cantor(a);
    	if (state_num == 0) return a.g;
    	visited[state_num] = true;

    	for (int i = 0; i < 4; i++) {
    		next = a;
    		next.x+=move[i][0];    
            next.y+=move[i][1];
            if(next.x<0||next.y<0||next.x>2||next.y>2) continue;    
            next.map[a.x][a.y]=a.map[next.x][next.y];
            next.map[next.x][next.y]=0;    
            next.g+=1;    
            //next.h=getH_1(next);
			next.h=getH_2(next);    
            next.f=next.g+next.h;    
            int next_state_num=Cantor(next);
            if(visited[next_state_num]) continue;  
            Q.push(next);   
    	}
    }
    return -1;
}

int main()    
{      
    Hash[0]=1;    
    for(int i=1;i<=9;i++) Hash[i]=Hash[i-1]*i;    

    int a;
    node start;
    for(int i=0;i<3;i++)  
    {  
        for(int j=0;j<3;j++)  
        {  
            cin>>a;  
            start.map[i][j]=a;  
            if(a==0)    
            {   
	            start.x=i;  
	            start.y=j;  
            }  
        }  
    }  
    if(!check(start))    
    {    
        cout<<"No Solution!"<<endl;    
    }    
    else cout<<search(start)<<endl; 
	return 0;
}  
