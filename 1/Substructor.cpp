#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <random>
#include <iostream>
#include <string>
#include "Substructor.h"
using namespace std;
Substructor::Substructor() {
    n = 20;
    vector<double>z(n);
    v = z;
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}
Substructor::Substructor(int k) {
    n = k;
    vector<double>z(n);
    v = z;
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}
Substructor::~Substructor() {
    cout << "\n������� ������ Substructor ��� ������." << endl;
    v.clear();
}
void Substructor::setOperand(double value, size_t pos) {
    v[pos - 1] = value;
    cout << "�������� �� ������� " << pos << " ���� ��������� �������� " << value << endl;
}
void Substructor::shuffleOperands() {
    cout << "\n����� ������� ���������:" << endl;
    partition(v.begin(), v.end(), [](int i)->bool {
        return i < 0;
        });
    int k = 0;
    for (auto it : v) {
        if (k < n - 1) {
            if (it < 0) cout << '(' << it << ')' << " - ";
            else cout << it << " - ";
            k++;
        }
        else {
            if (it < 0) cout << '(' << it << ')';
            else cout << it;
            k++;
        }
    }
}
void Substructor::shuffleOperands(int i, int j) {
    if (v[i] < 0 && v[j] >= 0) {
        v[i] += v[j];
        v[j] = v[i] - v[j];
        v[i] -= v[j];
        cout << "�������� ��� �������� " << i << " ���� ��������� �������� " << v[i] << endl;
        cout << "�������� ��� �������� " << j << " ���� ��������� �������� " << v[j] << endl;
    }
}
void Substructor::setOperands(double* new_operands, size_t size) {
    for (int i = 0; i < v.size(); i++) {
        if (i < size) v[i] = new_operands[i];
    }
}
void Substructor::displayOperation() {
    cout << "\n��������� Substructor: " << endl;
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
            if (v[i] < 0) cout << '(' << v[i] << ')';
            else cout << v[i];
        }
        else if (v[i] < 0) cout << '(' << v[i] << ')' << " - ";
        else cout << v[i] << " - ";
    }
    cout << endl;
}
void Substructor::calculate() {
    cout << "\n�������: " << endl;
    double tmp = v[0];
    for (int i = 1; i < n;i++) {
        logcout((to_string(tmp) + " - " + to_string(v[i]) + " = "));
        logtofile((to_string(tmp) + " - " + to_string(v[i]) + " = "), "file.txt");
        tmp -= v[i];
        logcout(to_string(tmp) + '\n');
        logtofile(to_string(tmp) + '\n', "file.txt");
    }
    cout << "���������:\n--------------------------------------- " << tmp << endl<<endl;
}
void Substructor::logcout(string text){
    cout << text;
}
void Substructor::logtofile(string text, string filename) {
    ofstream out;
    out.open(filename, ios::app);
    if (out.is_open())
    {
        out << text << endl;
    }
    out.close();
}