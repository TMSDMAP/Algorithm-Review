#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int start = 0;
	int end;

	while ((end = s.find(' ', start)) != string::npos) {
		reverse(s.begin() + start, s.begin() + end);
		start = end + 1;
	}
	reverse(s.begin() + start, s.end());
	cout << s << endl;
	return 0;
}
