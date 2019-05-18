#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Person{
	string name;
	string surname;
	int age;
};

int main(){
	map<string, Person> name_to_value;
	name_to_value["first"] = {"Anton", "Taleckij", 22};

	cout << name_to_value["first"].name;
}
