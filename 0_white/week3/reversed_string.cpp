#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReversibleString{
    public:
        ReversibleString(){
            string_value = "";
        }
        ReversibleString(const string& s){
            string_value = s;
        }
        void Reverse(){
            is_reversed = !is_reversed;
        }
        string ToString() const{
            if (is_reversed){
                vector<char> v(string_value.size());
                int i = string_value.size() - 1;
                for (const auto& chr: string_value){
                    v[i--] = chr;
                }
                return string(begin(v), end(v));
            } else {
                return string_value;
            }
        }
    private:
        string string_value;
        bool is_reversed = false;

};

int main(){
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
