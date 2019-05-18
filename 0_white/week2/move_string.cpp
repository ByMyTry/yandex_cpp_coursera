#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
	for (auto s: source){
		destination.push_back(s);
	}
	source.clear();
}

void PrintVector(vector<string> vs){
	for(auto s: vs){
		cout << s << " ";
	}
	cout << endl;
}

int main(){
	vector<string> vs1 = {"a", "b", "c"}, vs2 = {"z"};
	MoveStrings(vs1, vs2);
	PrintVector(vs1);
	PrintVector(vs2);
	return 0;
}
