#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <random>
#include <iostream>
#include <string>
#include "Multiplier.h"
using namespace std;
Multiplier::Multiplier() {
    n = 20;
    vector<double>z(n);
    v = z;
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}
Multiplier::Multiplier(int k) {
    n = k;
    vector<double>z(n);
    v = z;
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}
Multiplier::~Multiplier() {
    cout << "\n������� ������ Multiplier ��� ������." << endl;
    v.clear();
}
void Multiplier::setOperand(double value, size_t pos) {
    v[pos - 1] = value;
    cout << "�������� �� ������� " << pos << " ���� ��������� �������� " << value << endl;
}
void Multiplier::shuffleOperands() {
    cout << "\n����� ������� ���������: " << endl;
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);
    copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, "   "));
    cout << endl;
}
void Multiplier::shufflebetween2(int i, int j) {
    v[i] += v[j];
    v[j] = v[i] - v[j];
    v[i] -= v[j];
    cout << "�������� ��� �������� " << i << " ���� ��������� �������� " << v[i] << endl;
    cout << "�������� ��� �������� " << j << " ���� ��������� �������� " << v[j] << endl;
}
void Multiplier::setOperands(double* new_operands, size_t size) {
    for (int i = 0; i < v.size(); i++) {
        if (i < size) v[i] = new_operands[i];
    }
}
void Multiplier::displayOperation() {
    cout << "\n��������� Multiplier: " << endl;
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
            if (v[i] < 0) cout << '(' << v[i] << ')';
            else cout << v[i];
        }
        else if (v[i] < 0) cout << '(' << v[i] << ')' << " * ";
        else cout << v[i] << " * ";
    }
    cout << endl;
}
void Multiplier::calculate() {
    cout << "\n�������: " << endl;
    double tmp = v[0];
    for (int i = 1; i < n;i++) {
        logcout((to_string(tmp) + " * " + to_string(v[i]) + " = "));
        logtofile((to_string(tmp) + " * " + to_string(v[i]) + " = "), "file.txt");
        tmp *= v[i];
        logcout(to_string(tmp) + '\n');
        logtofile(to_string(tmp) + '\n', "file.txt");
    }
    cout << "���������: " << tmp << "\n--------------------------------------" << endl;
}
void Multiplier::logcout(string text) {
    cout << text;
}
void Multiplier::logtofile(string text, string filename) {
    ofstream out;
    out.open(filename, ios::app);
    if (out.is_open())
    {
        out << text << endl;
    }
    out.close();
}