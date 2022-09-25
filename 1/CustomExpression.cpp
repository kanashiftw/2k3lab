#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <random>
#include <iostream>
#include <string>
#include "CustomExpression.h"
using namespace std;
CustomExpression::CustomExpression() {
    n = 20;
    vector<double>z(n);
    v = z;
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}
CustomExpression::CustomExpression(int k) {
    n = k;
    vector<double>z(n);
    v = z;
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}
CustomExpression::~CustomExpression() {
    cout << "\nЭлемент класса Custom Expression был удален." << endl;
    v.clear();
}
void CustomExpression::setOperand(double value, size_t pos) {
    v[pos - 1] = value;
    cout << "Операнду на позиции " << pos << " было присвоено значение " << value << endl;
}
void CustomExpression::shuffleOperands() {
    cout << "\nНовый порядок операндов: " << endl;
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);
    copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, "   "));
    cout << endl;
}
void CustomExpression::shufflebetween2(int i, int j) {
    v[i] += v[j];
    v[j] = v[i] - v[j];
    v[i] -= v[j];
    cout << "Операнду под индексом " << i << " было присвоено значение " << v[i] << endl;
    cout << "Операнду под индексом " << j << " было присвоено значение " << v[j] << endl;
}
void CustomExpression::setOperands(double* new_operands, size_t size) {
    for (int i = 0; i < v.size(); i++) {
        if (i < size) v[i] = new_operands[i];
    }
}
void CustomExpression::displayOperation() {
    cout << "\nВыражение CustomExpression: " << endl;
    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0) {
            if (i == v.size() - 1) {
                if (v[i] < 0) cout << '(' << v[i] << ')';
                else cout << v[i];
            }
            else if (v[i] < 0) cout << '(' << v[i] << ')' << " + ";
            else cout << v[i] << " + ";
        }
        else {
            if (i == v.size() - 1) {
                if (v[i] < 0) cout << '(' << v[i] << ')';
                else cout << v[i];
            }
            else if (v[i] < 0) cout << '(' << v[i] << ')' << " - ";
            else cout << v[i] << " - ";
        }
    }
    cout << endl;
}
void CustomExpression::calculate() {
    cout << "\nРешение: " << endl;
    double tmp = v[0];
    for (int i = 1; i < n;i++) {
        if (i % 2 == 0) {
            logcout((to_string(tmp) + " + " + to_string(v[i]) + " = "));
            logtofile((to_string(tmp) + " + " + to_string(v[i]) + " = "), "file.txt");
            tmp += v[i];
            logcout(to_string(tmp) + '\n');
            logtofile(to_string(tmp) + '\n', "file.txt");
        }
        else {
            logcout((to_string(tmp) + " - " + to_string(v[i]) + " = "));
            logtofile((to_string(tmp) + " - " + to_string(v[i]) + " = "), "file.txt");
            tmp -= v[i];
            logcout(to_string(tmp) + '\n');
            logtofile(to_string(tmp) + '\n', "file.txt");

        }
    }
    cout << "Результат: " << tmp << "\n--------------------------------------" << endl;
}
void CustomExpression::logcout(string text) {
    cout << text;
}
void CustomExpression::logtofile(string text, string filename) {
    ofstream out;
    out.open(filename, ios::app);
    if (out.is_open())
    {
        out << text << endl;
    }
    out.close();
}