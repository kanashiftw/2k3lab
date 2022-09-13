#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
using namespace std;
#define login(name) cout << "\n -->" << name<<'\n';
#define logout(name) cout << "\n <--" << name<<'\n';


class Systematize {
private:
    char c[6];
    vector<int> v;
public:
    Systematize(string some_text) {
        login("Systematize");
        cout << endl;
        int k = 0;
        cout << "Операторы: ";
        for (int i = 0; i < some_text.length(); i++) {
            if (!isdigit(some_text[i])) {
                c[k] = some_text[i];
                cout << c[k];
                some_text[i] = ' ';
                k++;
            }
        }
        cout << endl;
        stringstream ss(some_text);
        cout << "Операнды: ";
        copy(istream_iterator<int>(ss), {}, back_inserter(v));
        copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
        cout << endl;
        logout("Systematize");
}
    void priorities() {

    }
    void calculate() {
        login("calculate");
        cout << endl;
        int k = 1;
        int tmp = v[0];
        for (int i = 0; i < 3;i++) {
            switch (c[i]) {
            case '+': 
                tmp += v[k];
                k++;
                break;
            case '-': 
                tmp -= v[k];
                k++;
                break;
            case'*': 
                tmp *= v[k];
                k++;
                break;
            case'/': 
                tmp /= v[k];
                k++;  
                break;
            }
        }
        cout << "Результат: " << tmp;
        cout << endl;
        logout("calculate");
    }
};

int main()
{
    login("main");
    cout << endl;
    setlocale(LC_ALL, "Russian");
    string line = "8-2/2+1";
    logout("main");
    cout << endl;
    Systematize a(line);
    a.calculate();
}

