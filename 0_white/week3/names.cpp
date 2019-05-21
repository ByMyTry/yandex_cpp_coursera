#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct PersonNames
{
    string name;
    string last_name;
};

class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {
            if (names_changes.count(year) > 0){
                names_changes[year].name = first_name;
            } else {
                names_changes[year] = {first_name, ""};
            }
        }
        void ChangeLastName(int year, const string& last_name) {
            if (names_changes.count(year) > 0){
                names_changes[year].last_name = last_name;
            } else {
                names_changes[year] = {"", last_name};
            }
        }
        string GetFullName(int year) {
            PersonNames person_names = {"", ""};
            for (const auto& item: names_changes){
                if (item.first > year){
                    break;
                }
                if (item.second.name != ""){
                    person_names.name = item.second.name;
                }
                if (item.second.last_name != ""){
                    person_names.last_name = item.second.last_name;
                }
            }
            return GetFullName(person_names);
        }
    private:
        map<int, PersonNames> names_changes;
        string GetFullName(const PersonNames& person_names) {
            if (person_names.name == "" && person_names.last_name == ""){
                return "Incognito";
            } else if (person_names.last_name == "") {
                return person_names.name + " with unknown last name";
            } else if (person_names.name == "") {
                return person_names.last_name + " with unknown first name";
            } else {
                return person_names.name + " " + person_names.last_name;
            }
        }
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
