#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    int strings_count;
    cin >> strings_count;
    set<string> unique_strings;
    for (int i = 0; i < strings_count; ++i){
        string current_string;
        cin >> current_string;
        unique_strings.insert(current_string);
    }
    cout << unique_strings.size() << endl;
    return 0;
}
