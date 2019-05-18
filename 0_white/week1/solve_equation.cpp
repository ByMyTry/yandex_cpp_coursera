#include <cmath>
#include <iostream>

using namespace std;

int main(){
	float a, b, c;
	cin >> a >> b >> c;
	if (a != 0){
		float D = b * b - 4 * a * c;
		if (D > 0) {
			float x1 = (-b + sqrt(D)) / (2 * a);
			float x2 = (-b - sqrt(D)) / (2 * a);
			cout << x1 << ' ' << x2 << endl;
		} else if (D == 0) {
			cout << -b / (2*a) << endl;
		}
	} else {
		if (b != 0){
			 cout << -c / b << endl;
		}
	}
	return 0;
}
