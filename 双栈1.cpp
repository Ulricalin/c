#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

bool Edge[1001][1001];
int color[1001];

bool can_output = true;
void dfs(int n, int colour, int pos) {
    color[pos] = colour;
    for (int i = 0; i < n; i++) {
        if (Edge[i][pos]) {
            if (color[i] == colour) {
                can_output = false;
                break;
            } else if (!color[i]) {
                dfs(n, 3-colour, i);
            }
        }
    }
}
int main() {
    int n;
    while (cin >> n) {
        can_output = true;
        int num[1001];
        int MIN[1001];
        for (int i = 0; i < n; i++) {
        	color[i] = 0;
            for (int j = 0; j < n; j++) {
                Edge[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) cin >> num[i];
        MIN[n-1] = num[n-1];
        for (int i = n-2; i >= 0; i--) {
            MIN[i] = min(num[i], MIN[i+1]);
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (num[i] < num[j] && MIN[j] < num[i]) {
                    Edge[i][j] = Edge[j][i] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!color[i]) dfs(n, 1, i);
        }
        string s;
        stack<int> Stack1, Stack2;
        int e = 0;
        if (can_output) {
            for (int i = 0; i < n; i++) {
                if (color[i] == 1) {
                    Stack1.push(num[i]);
                    s += 'a';
                } else {
                    Stack2.push(num[i]);
                    s += 'c';
                }
                while (!Stack1.empty() && e == Stack1.top()-1) {
                    Stack1.pop();
                    e++;
                    s += 'b';
                    while (!Stack2.empty() && e == Stack2.top()-1) {
                        Stack2.pop();
                        e++;
                        s += 'd';
                    }
                }
                while (!Stack2.empty() && e == Stack2.top()-1) {
                    Stack2.pop();
                    e++;
                    s += 'd';
                    while (!Stack1.empty() && e == Stack1.top()-1) {
                        Stack1.pop();
                        e++;
                        s += 'b';
                    }
                }
            }
            cout << s[0];
            for (int i = 1; i < s.length(); i++) {
                cout << ' ' << s[i];
            }
            cout << endl;
        } else {
            cout << '0' << endl;
        }
    }
    return 0;
}
