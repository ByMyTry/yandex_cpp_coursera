#include <iostream>

using namespace std;

int Factorial(int n){
	int res = 1;
	for(int i = 1; i <= n; ++i){
		res *= i;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	cout << Factorial(n) << endl;
	return 0;
}
