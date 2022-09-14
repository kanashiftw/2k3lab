#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <random>
using namespace std;

#define login  cout << "\n -->" << __FUNCTION__<<'\n';

#define logout cout << "\n <--" << __FUNCTION__<<'\n';

class Systematize {
private:
    char c[100];
    vector<int> v;
public:
    Systematize(string some_text) {
        login;
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
        cout << '\t';
        stringstream ss(some_text);
        cout << "Операнды: ";
        copy(istream_iterator<int>(ss), {}, back_inserter(v));
        copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
        logout;
}
    void priorities() {
        
    }
    void setoperand(int pos, int value) {
        login;
        v[pos-1] = value;
        cout << "Операнду на позиции " << pos << " было присвоено значение " << value;
        logout;
    }
    void shuffleoperands() {
        login;
        cout << "Новый порядок операндов: ";
        random_device rd;
        mt19937 g(rd());
        shuffle(v.begin(), v.end(), g);
        copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        logout;
    }
    void shufflebetween2(int i, int j) {
        login;
        v[i] += v[j];
        v[j] = v[i] - v[j];
        v[i] -= v[j];
        cout << "Операнду под индексом " << i << " было присвоено значение " << v[i] << endl;
        cout << "Операнду под индексом " << j << " было присвоено значение " << v[j] << endl;;
        logout;
    }
    void calculate() {
        login;
        int k = 1;
        int tmp = v[0];
        for (int i = 0; c[i] != 0;i++) {
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
        logout;
    }
    ~Systematize() {
        login;
        cout << "Элемент класса был удален.";
        logout;
    }
};

int main()
{
    login;
    setlocale(LC_ALL, "Russian");
    string line = "10-2*2+1";
    logout;
    Systematize a(line);
    a.setoperand(2, 4);
    a.shuffleoperands();
    a.shufflebetween2(1, 2);
    a.calculate();
}
