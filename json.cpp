#include <iostream>
#include <string>
#include <map>
 
using std::ostream;
using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::map;
 
class json {
 private:
    // store the relationship between key and value
    map<string, string> _data;
 public:
    // parse the raw string to map<string, string>
    explicit json(string);
 
    // return mutable value according to key
    string& operator[](string key) {
        return _data[key];
    }
 
    // return the number of key/value
    int count() const {
        return _data.size();
    }
 
    // output
    friend ostream& operator<<(ostream& os, const json& obj) {
        map<string, string>::iterator it;
        map<string, string> data = obj._data;
        int num = 0;
        os << "{\n";
        for (it = data.begin(); it != data.end(); it++) {
            num++;
            os << "    \"" << it->first << "\": \"" << it->second << "\"";
            if (num != obj.count()) {
                os << ",";
            }
            os << "\n";
        }
        os << "}";
        return os;
    }
};
json::json(string s11) {
	int index = s11.find(":");
	int begin = 2;
	string key, value;
	while (index != string::npos) {
		key = s11.substr(begin, index-1-begin);
		begin = index+2;
		index = s11.find("\"", begin);
		value = s11.substr(begin, index-begin);
		_data[key] = value;
		begin = index+3;
		index = s11.find(":", begin);
	}
}
int main(void) {
    {
        // {"name":"lilei","country":"china","age":"20"}
        json test("{\"name\":\"lilei\",\"country\":\"china\",\"age\":\"20\"}");
        cout << test << endl;
        test["name"] = "mike";
        test["country"] = "USA";
        cout << test << endl;
    }
    {
        // {"book_name":"c++ primer 5th","price":"$19.99"}
        json test("{\"book_name\":\"c++ primer 5th\",\"price\":\"$19.99\"}");
        cout << test << endl;
        test["page"] = "345";
        test["ISBN"] = "978-962";
        cout << test << endl;
    }
    {
        int AvoidRepeatedData;
        cin >> AvoidRepeatedData;
        string rawString;
        cin >> rawString;
        json test(rawString);
        cout << test << endl;
    }
    return 0;
}

