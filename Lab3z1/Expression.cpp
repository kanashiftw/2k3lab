#include "Expression.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <random>
ofstream out;
using namespace std;
Expression::Expression() {
    v[20];
    for (int i = 0; i < 20; i++) {
        v[i] = 0;
    }
}
Expression::Expression(int n) {
    v[n];
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}
Expression::Expression(string some_text) {
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
    cout << endl;
}
Expression::~Expression() {
    cout << "Элемент класса был удален." << endl;
}
void Expression::setOperand(double value, size_t pos) {
    v[pos - 1] = value;
    cout << "Операнду на позиции " << pos << " было присвоено значение " << value << endl;
}
void Expression::shuffleOperands(){
    cout << "Новый порядок операндов: " << endl;
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);
    copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, "   "));
    cout << endl;
}
void Expression::shufflebetween2(int i, int j){
    v[i] += v[j];
    v[j] = v[i] - v[j];
    v[i] -= v[j];
    cout << "Операнду под индексом " << i << " было присвоено значение " << v[i] << endl;
    cout << "Операнду под индексом " << j << " было присвоено значение " << v[j] << endl;
}
void Expression::setOperands(double* new_operands, size_t size) {
    cout << "Новый порядок операндов: " << endl;
    for (int i = 0; i < v.size(); i++) {
        if (i < size) {
            v[i] = new_operands[i];
            cout << v[i] << ' ';
        }
        else  cout << v[i] << ' ';
    }
    cout << endl;
}
void Expression::calculate(){
    int k = 1;
    double tmp = v[0];
    for (int i = 0; c[i] != 0;i++) {
        switch (c[i]) {
        case '+':
            logcout((to_string(tmp) + " + " + to_string(v[k]) + " = "));
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
void Expression::logcout(string text){
    cout << text;
}
void Expression::logtofile(string text, string filename){
    out.open(filename, ios::app);
    if (out.is_open())
    {
        out << text << endl;
    }
    out.close();
}