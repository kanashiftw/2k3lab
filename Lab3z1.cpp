#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
using namespace std;

#define login cout << "\n -->" << __FUNCTION__<<'\n';
#define logout cout << "\n <--" << __FUNCTION__<<'\n';


class Systematize {
private:
    char c[6];
    vector<int> v;
public:
    Systematize(string some_text) {
        login;
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
        logout;
}
    void priorities() {

    }
    void setoperand(int pos, int value) {
        login;
        v[pos] = value;
        cout << "\nОперанду на позиции " << pos << " было присвоено значение " << value<<endl;
        logout;
    }
    void calculate() {
        login;
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
        logout;
    }
};

int main()
{
    login;
    cout << endl;
    setlocale(LC_ALL, "Russian");
    string line = "8-2/2+1";
    logout;
    cout << endl;
    Systematize a(line);
    a.setoperand(2, 4);
    a.calculate();
}

