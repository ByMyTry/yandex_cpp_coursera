#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string tolower(const string& s){
    vector<char> result;
    for (const auto& chr: s){
        result.push_back(tolower(chr));
    }
    return string(begin(result), end(result));
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (auto& word: words){
        cin >> word;
    }
    sort(begin(words), end(words), 
        [](const string& word1, const string& word2){
            return tolower(word1) < tolower(word2);
        }
    );
    for (auto& word: words){
        cout << word << ' ';
    }
    cout << endl;
    return 0;
}
