#include <iostream>
#include <cmath>

using namespace std;

int min(int a, int b){
	if (a <= b){
		return a;
	} else {
		return b;
	}
}

int main(){
	int a, b;
	cin >> a >> b;
	int min_abs_number = min(abs(a), abs(b));
	int max_d = 1;
	for (int i = 2; i <= min_abs_number; ++i){
		if ((abs(a) % i == 0) && (abs(b) % i == 0)){
			max_d = i;
		}
	}
	cout << max_d << endl;
	return 0;
}
