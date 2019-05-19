#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (auto& number: numbers){
        cin >> number;
    }
    sort(begin(numbers), end(numbers), [](int n1, int n2){return abs(n1) < abs(n2);});
    for (const auto& number: numbers){
        cout << number << ' ';
    }
    cout << endl;
    return 0;
}
