/*
struct Incognizable {
  int x = 0;
  int y = 0;
};
*/

class Incognizable{
    public:
        Incognizable(){
            number1 = 1;
            number2 = 2;
        }
        Incognizable(const int& n1){
            number1 = n1;
        }
        Incognizable(const int& n1, const int& n2){
            number1 = n1;
            number2 = n2;
        }
    private:
        int number1 = 0;
        int number2 = 0;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}