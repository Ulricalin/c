#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
using std::string;
int main() {
	vector<string> mystrings;
    string s;
    string s1;
    bool even = false;
    stringstream ss;
    while (getline(cin, s)) {
    	ss.str("");
        bool flag = false;
        for (int i = 0; i < s.length(); i++) {
        	if (s[i] != ' ') {
        		flag = true;
        		break;
			}
		}
		if (flag) {
			for (int i = s.length()/2.0-0.5; i >= 0; i--) {
	            ss << s[i];
	        }
	        for (int i = s.length()-1; i > s.length()/2.0-0.5; i--) {
	            ss << s[i];
	        }
		}
        if (even) {
        	if (ss.str().size() > 0) mystrings.push_back(ss.str());
        	if (s1.size() > 0) mystrings.push_back(s1);
        	even = false;
		} else {
			s1 = ss.str();
			even = true;
		}
    }
    for (int i = 0; i < mystrings.size(); i++) {
    	cout << mystrings[i] << endl;
	}
    return 0;
}
