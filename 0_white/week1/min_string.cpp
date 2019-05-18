#include <iostream>
#include <string>

using namespace std;

string min_string(string s1, string s2){
	if(s1 < s2){
		return s1;
	}else{
		return s2;
	}
}

int main(){
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	cout << min_string(min_string(s1, s2), s3) << endl;
}
