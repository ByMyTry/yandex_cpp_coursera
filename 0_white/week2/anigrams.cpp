#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, int> BuildCharCounters(const string& word){
	map<char, int> result;
	for(const auto& chr : word){
		++result[chr];
	}
	return result;
}

int main(){
	int n;
	cin >> n;
	vector<vector<string>> words;
	map<bool, string> bool_to_print {{true, "YES"}, {false, "NO"}};
	for(int i = 0; i < n; ++i){
		string first_word, second_word;
		cin >> first_word >> second_word;
		cout << bool_to_print[
			BuildCharCounters(first_word) == BuildCharCounters(second_word)
		] << endl;
	}
}
