#include <iostream>
#include <cctype>
using namespace std;

string hToBc(char c) {
	c = toupper(c);
	string s;
	switch(c) {
		case '0':
			s = "0000";
			return s;
		case '1':
			s = "0001";
			return s;
		case '2':
			s = "0010";
			return s;
		case '3':
			s = "0011";
			return s;
		case '4':
			s = "0100";
			return s;
		case '5':
			s = "0101";
			return s;
		case '6':
			s = "0110";
			return s;
		case '7':
			s = "0111";
			return s;
		case '8':
			s = "1000";
			return s;
		case '9':
			s = "1001";
			return s;
		case 'A':
			s = "1010";
			return s;
		case 'B':
			s = "1011";
			return s;
		case 'C':
			s = "1100";
			return s;
		case 'D':
			s = "1101";
			return s;
		case 'E':
			s = "1110";
			return s;
		case 'F':
			s = "1111";
			return s;
	}
	return s;
}
string hToBs(string s) {
	string ans;
	for (int i = 0; i < s.length(); i++) {
		ans += hToBc(s[i]);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		temp = temp.substr(2);
		s += hToBs(temp);
	}
	cout << s << endl;
}