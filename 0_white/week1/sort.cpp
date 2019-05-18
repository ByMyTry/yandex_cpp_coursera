#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> nums = {4, 3, 5, 1, 5};
	sort(begin(nums), end(nums));
	for(auto i: nums){
		cout << i << ',';
	}
	cout << '\n';
}
