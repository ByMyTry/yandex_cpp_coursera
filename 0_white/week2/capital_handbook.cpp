#include <iostream>
#include <string>
#include <map>

using namespace std;

void change_capital(map<string, string>& capital_handbook, const string& country,
const string& new_capital){
	if (capital_handbook.count(country) > 0){
		if (capital_handbook[country] == new_capital){
			cout << "Country " << country << " hasn't changed its capital" << endl;
		} else {
			cout << "Country " << country << " has changed its capital from " << capital_handbook[country] << " to " << new_capital << endl;
		}
	} else {
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	}
	capital_handbook[country] = new_capital;
}

void rename(map<string, string>& capital_handbook, const string& old_country_name,
const string& new_country_name){
	if ((old_country_name == new_country_name) || (capital_handbook.count(new_country_name) > 0) || (capital_handbook.count(old_country_name) == 0)){
		cout << "Incorrect rename, skip" << endl;
	} else {
		cout << "Country " << old_country_name << " with capital " << capital_handbook[old_country_name] << " has been renamed to " << new_country_name << endl;
		capital_handbook[new_country_name] = capital_handbook[old_country_name];
		capital_handbook.erase(old_country_name);
	}
}

void about(map<string, string>& capital_handbook, const string& country){
	if (capital_handbook.count(country) > 0){
		cout << "Country " << country << " has capital " << capital_handbook[country] << endl;
	} else {
		cout << "Country " << country << " doesn't exist" << endl;
	}
}

void dump(const map<string, string>& capital_handbook){
	if (capital_handbook.size() == 0){
		cout << "There are no countries in the world" << endl;
	} else {
		for (auto item: capital_handbook){
			cout << item.first << '/' << item.second << ' ';
		}
		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;
	map<string, string> capital_handbook;
	string command;
	for (int i = 0; i < n; ++i){
		cin >> command;
		if (command == "CHANGE_CAPITAL"){
			string country, new_capital;
			cin >> country >> new_capital;
			change_capital(capital_handbook, country, new_capital);
		} else if (command == "RENAME"){
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
                        rename(capital_handbook, old_country_name, new_country_name);
                } else if(command == "ABOUT"){
			string country;
			cin >> country;
                        about(capital_handbook, country);
                } else if(command == "DUMP"){
                        dump(capital_handbook);
                }
	}
	return 0;
}
