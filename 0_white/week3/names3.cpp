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

struct PersonNamesHistory
{
    vector<string> first_names;
    vector<string> last_names;
};

class Person {
    public:
        Person(const string& first_name, const string& last_name, const int& by){
            names_changes[by] = {first_name, last_name};
            birth_year = by;
        }
        void ChangeFirstName(int year, const string& first_name) {
            if (year >= birth_year) {
                if (names_changes.count(year) > 0){
                    names_changes[year].name = first_name;
                } else {
                    names_changes[year] = {first_name, ""};
                }
            }
        }
        void ChangeLastName(int year, const string& last_name) {
            if (year >= birth_year) {
                if (names_changes.count(year) > 0){
                    names_changes[year].last_name = last_name;
                } else {
                    names_changes[year] = {"", last_name};
                }
            }
        }
        string GetFullName(int year) {
            if (year < birth_year) {
                return "No person";
            }
            PersonNames person_names = {"", ""};
            for (const auto& item: names_changes){
                if (item.first > year){
                    break;
                }
                if (item.second.name != ""){
                    person_names.name = item.second.name;
                } else {
                    person_names.last_name = item.second.last_name;
                }
            }
            return PersonNamesToStr(person_names);
        }
        string GetFullNameWithHistory(int year) {
            if (year < birth_year) {
                return "No person";
            }
            PersonNamesHistory person_names_history = {{}, {}};
            for (const auto& item: names_changes){
                if (item.first > year){
                    break;
                }
                if (item.second.name != ""){
                    int size = person_names_history.first_names.size();
                    if((size == 0) || (size > 0 && person_names_history.first_names[size - 1] != item.second.name)){
                        person_names_history.first_names.push_back(item.second.name);
                    }
                }
                if (item.second.last_name != "") {
                    int size = person_names_history.last_names.size();
                    if((size == 0) || (size > 0 && person_names_history.last_names[size - 1] != item.second.last_name)){
                        person_names_history.last_names.push_back(item.second.last_name);
                    }
                }
            }
            return PersonNamesWithHistoryToStr(person_names_history);
        }
    private:
        int birth_year;
        map<int, PersonNames> names_changes;
        string PersonNamesToStr(const PersonNames& person_names) {
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
        string PersonNamesWithHistoryToStr(const PersonNamesHistory& person_names_history){
            if (person_names_history.first_names.size() == 0 && person_names_history.last_names.size() == 0){
                return "Incognito";
            } else if (person_names_history.last_names.size() == 0) {
                return NameHistoryToStr(person_names_history.first_names) + " with unknown last name";
            } else if (person_names_history.first_names.size() == 0) {
                return NameHistoryToStr(person_names_history.last_names) + " with unknown last name";
            } else {
                return NameHistoryToStr(person_names_history.first_names) + " " + NameHistoryToStr(person_names_history.last_names);
            }
        }
        string NameHistoryToStr(const vector<string>& name_history){
            int size = name_history.size();
            string result = name_history[size - 1];
            if (size > 1){
                result += " (";
            }
            int counter = 0;
            for (int i = size - 2; i >= 0; --i){
                if (counter > 0){
                    result += ", " + name_history[i];
                } else {
                    result += name_history[i];
                }
                counter++;
            }
            if (size > 1){
                result += ")";
            }
            return result;
        }
        
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

return 0;
}
