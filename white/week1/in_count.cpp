#include <iostream>
#include <string>

using namespace std;

int SEARCHED_LETTER = 'f';

int main() {
	string s;
	cin >> s;
	int reversed_count = -2;
	for (int i = 0; i <= s.size(); ++i){
		if (s[i] == SEARCHED_LETTER){
			reversed_count += 1;
			if (reversed_count == 0) {
				cout << i << endl;
				break;
			}
		}
	}
	if (reversed_count != 0) {
		cout << reversed_count << endl;
	}
	return 0;
}
