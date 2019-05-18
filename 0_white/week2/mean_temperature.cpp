#include <iostream>
#include <vector>

using namespace std;

void ReadIntVector(vector<int>& v){
	for(int& number: v){
                cin >> number;
        }
}

int Mean(const vector<int>& v){
	int sum = 0;
	for(auto number: v){
		sum += number;
	}
	return sum/v.size();
}

vector<int> FilterByTreshold(const vector<int>& days_temperatures, int mean){
	vector<int> res;
	int i = 0;
	for(auto temperature: days_temperatures){
		if(temperature > mean){
			res.push_back(i);
		}
		i++;
	}
	return res;
}

void PrintVector(const vector<int>& v){
	int i = 0;
	for (auto number: v){
		if (i < v.size() - 1){
			cout << number << ' ';
		} else {
			cout << number << '\n';
		}
		i++;
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> days_temperatures(n);
	ReadIntVector(days_temperatures);
	int mean = Mean(days_temperatures);
	vector<int> filtered_days_temperatures = FilterByTreshold(days_temperatures, mean);
	cout << filtered_days_temperatures.size() << endl;
	PrintVector(filtered_days_temperatures);
}
