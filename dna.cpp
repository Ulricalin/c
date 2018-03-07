#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
using std::string;
bool match(char a, char b) {
    if (a == 'A' && b == 'T') return true;
    if (a == 'T' && b == 'A') return true;
    if (a == 'C' && b == 'G') return true;
    if (a == 'G' && b == 'C') return true;
    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char dna[101][101];
        bool ismatch = false;
        int count = 0;
        for (int i = 0; i < n; i++) {
            cin >> dna[i];
        }
        for (int i = 0; i < n-1; i++) {
        	if (dna[i][0] == '0') continue;
            for (int j = i+1; j < n; j++) {
            	if (dna[j][0] == '0') continue;
                ismatch = true;
                if (strlen(dna[i]) != strlen(dna[j])) ismatch = false;
                else {
                	for (int k = 0; k < strlen(dna[i]); k++) {
	                    if (!match(dna[i][k], dna[j][k])) {
	                        ismatch = false;
	                        break;
	                    }
	                }
				}
                if (ismatch) {
                	count++;
                	dna[i][0] = dna[j][0] = '0';
                	break;
				}
            }
        }
        cout << count << endl;
    }
    return 0;
}
