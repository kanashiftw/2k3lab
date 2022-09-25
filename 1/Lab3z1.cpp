#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <random>
#include "Summator.h"
#include "Substructor.h"
#include "Multiplier.h"
#include "Divisior.h"
#include "CustomExpression.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Summator sum_test(7);
    double array[7] = {5,12.5,9,-1.5,-9.5,0,11};
    sum_test.setOperands(array, 7);
    sum_test.displayOperation();
    sum_test.calculate();
    CustomExpression ce_test(5);
    double ary[5] = { 5,4,-2,9,3 };
    ce_test.setOperands(ary,5);
    ce_test.displayOperation();
    ce_test.calculate();
    Divisior div_test(4);
    div_test.setOperand(100, 0);
    div_test.setOperand(-4, 1);
    div_test.setOperand(2.5, 2);
    div_test.setOperand(-4, 3);
    div_test.displayOperation();
    div_test.calculate();
    vector<IShuffle*> vector_of_pointers;
    vector_of_pointers.push_back(&sum_test);
    vector_of_pointers.push_back(&ce_test);
    vector_of_pointers.push_back(&div_test);
    for (int i = 0; i < vector_of_pointers.size();i++) {
        IShuffle* p = dynamic_cast<IShuffle*>(vector_of_pointers[i]);
        cout << "\n\nРезультат приведения dynamic_cast для Expression:" << endl;
        if (p) {
            cout << "\tПриведение корректно.\nБазовый класс: " << typeid(p).name() <<
                "\nПолученный класс: " << typeid(vector_of_pointers[i]).name();
            vector_of_pointers[i]->shuffleOperands();
        }
        else cout << "\tПриведение некорректно." << endl;
    }
}
