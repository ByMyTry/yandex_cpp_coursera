#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool check_synonyms_pair(const vector<set<string>>& synonyms_pairs, const string& word1, const string& word2){
    for (const auto& synonyms_pair : synonyms_pairs){
        if (synonyms_pair.count(word1) > 0 && synonyms_pair.count(word2) > 0){
            return true;
        }
    }
    return false;
}

int main(){
    int commands_count;
    cin >> commands_count;
    vector<set<string>> synonyms_pairs;
    for (int i = 0; i < commands_count; ++i){
        string command;
        cin >> command;
        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            bool is_synonyms_pair_exist = check_synonyms_pair(synonyms_pairs, word1, word2);    
            if (!is_synonyms_pair_exist){
                synonyms_pairs.push_back({word1, word2});
            }
        } else if (command == "COUNT") {
            string word;
            cin >> word;
            int synonyms_count = 0;
            for (const auto& synonyms_pair : synonyms_pairs){
                if (synonyms_pair.count(word) > 0){
                    synonyms_count++;
                }
            }
            cout << synonyms_count << endl;
        } else if (command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (check_synonyms_pair(synonyms_pairs, word1, word2)){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        
    }
    return 0;
}