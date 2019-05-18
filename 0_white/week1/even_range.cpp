#include <iostream>

using namespace std;

int main(){
	int a, b, start_number;
	cin >> a >> b;
	start_number = a + a % 2;
	if (start_number <= b){
		cout << start_number;
		start_number += 2;
	}
	for (int i = start_number; i <= b; i += 2){
		cout << ' ' << i;
	}
	return 0;
}
