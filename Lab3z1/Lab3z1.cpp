#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <random>
#include "Expression.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    string line = "10-2/2+1*245-2.5+14-19+3";
    Expression a(line);
    a.setOperand(2, 4);
    a.shuffleOperands();
    a.shufflebetween2(1, 2);
    double array[3] = { 1,2,3 };
    a.setOperands(array, 3);
    a.calculate();
}
