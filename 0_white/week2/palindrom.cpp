#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string s){
	int middle = s.size() / 2;
	for (int i = 0; i <= middle; ++i){
		if(s[i] != s[s.size() - 1 - i]){
			return false;
		}
	}
	return true;
}

int main(){
	string s;
	cin >> s;
	cout << IsPalindrom(s) << endl;
	return 0;
}
