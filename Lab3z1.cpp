#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <random>
using namespace std;
ofstream out;
class ILoggable {
public:
    virtual void calculate() = 0;
    virtual void logcout(string text) = 0;
    virtual void logtofile(string text, string filename) = 0;
};
//Класс для работы с выражением
class Expression : public ILoggable{
public:
    char c[100];
    vector<double> v;
    Expression(string some_text) {
        int k = 0;
        cout << "Операторы: ";
        for (int i = 0; i < some_text.length(); i++) {
            if (!isdigit(some_text[i]) && (some_text[i] != '.')) {
                c[k] = some_text[i];
                cout << c[k];
                some_text[i] = ' ';
                k++;
            }
        }
        stringstream ss(some_text);
        cout << "\tОперанды: ";
        copy(istream_iterator<double>(ss), {}, back_inserter(v));
        copy(begin(v), end(v), ostream_iterator<double>(cout, "   "));
        cout<<endl;
    }
    ~Expression() {
        cout << "Элемент класса был удален." << endl;
    }
    void setoperand(int pos, double value) {
        v[pos - 1] = value;
        cout << "Операнду на позиции " << pos << " было присвоено значение " << value << endl;
    }
    void shuffleoperands() {
        cout << "Новый порядок операндов: " << endl;
        random_device rd;
        mt19937 g(rd());
        shuffle(v.begin(), v.end(), g);
        copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, "   "));
        cout << endl;
    }
    void shufflebetween2(int i, int j) {
        v[i] += v[j];
        v[j] = v[i] - v[j];
        v[i] -= v[j];
        cout << "Операнду под индексом " << i << " было присвоено значение " << v[i] << endl;
        cout << "Операнду под индексом " << j << " было присвоено значение " << v[j] << endl;
    }
    virtual void calculate() override {
        int k = 1;
        double tmp = v[0];
        for (int i = 0; c[i] != 0;i++) {
            switch (c[i]) {
            case '+':
                logcout ((to_string(tmp) + " + " +   to_string(v[k]) + " = "));
                logtofile((to_string(tmp) + " + " + to_string(v[k]) + " = "), "file.txt");
                tmp += v[k];
                logcout(to_string(tmp) + '\n');
                logtofile(to_string(tmp) + '\n', "file.txt");
                k++;
                break;
            case '-':
                logcout((to_string(tmp) + " - " + to_string(v[k]) + " = "));
                logtofile((to_string(tmp) + " - " + to_string(v[k]) + " = "), "file.txt");
                tmp -= v[k];
                logcout(to_string(tmp) + '\n');
                logtofile(to_string(tmp) + '\n', "file.txt");
                k++;
                break;
            case'*':
                logcout((to_string(tmp) + " * " + to_string(v[k]) + " = "));
                logtofile((to_string(tmp) + " * " + to_string(v[k]) + " = "), "file.txt");
                tmp *= v[k];
                logcout(to_string(tmp) + '\n');
                logtofile(to_string(tmp) + '\n', "file.txt");
                k++;
                break;
            case'/':
                logcout((to_string(tmp) + " / " + to_string(v[k]) + " = "));
                logtofile((to_string(tmp) + " / " + to_string(v[k]) + " = "), "file.txt");
                tmp /= v[k];
                logcout(to_string(tmp) + '\n');
                logtofile(to_string(tmp) + '\n', "file.txt");
                k++;
                break;
            }
        }
        cout << "Результат: " << tmp << endl;
    }
    virtual void logcout(string text) override {
        cout << text;
    }
    virtual void logtofile(string text, string filename) override {
        out.open(filename, ios::app);
        if (out.is_open())
        {
            out << text <<endl;
        }
        out.close();
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    string line = "10-2*2+1*245-2.5+14-19/3";
    Expression a(line);
    a.setoperand(2, 4);
    a.shuffleoperands();
    a.shufflebetween2(1, 2);
    a.calculate();
}
