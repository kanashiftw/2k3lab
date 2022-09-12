#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
using namespace std;
struct Logger {
    void logToScreen(){
    
    }
    void logToFile(const string& filename){

    }
};

class Sumator {
private:
    int sum_of_elems = 0;
public:
    Sumator() {}
    Sumator(int * st) {
        vector<int> output;
        for (int i = 0; i < 5; i++) {
            output.push_back(st[i]);
        }
        for (vector<int>::iterator it = output.begin(); it != output.end(); ++it)
            sum_of_elems += *it;
    }
    void printSum(Sumator a) {
        cout <<"SUM\t"<<a.sum_of_elems;
    }
    ~Sumator(){}
};
class Subtructor {
private:
    int sub_of_elems = 0;
public:
    Subtructor() {}
    Subtructor(int * st) {
        vector<int> output;
        for (int i = 0; i < 6; i++) {
            if (i == 0) {
                sub_of_elems = st[i];
            }
            else {
                output.push_back(st[i]);
            }
        }
        for (vector<int>::iterator it = output.begin(); it != output.end(); ++it)
            sub_of_elems -= *it;
    }
    void printSub(Subtructor a) {
        cout << "DES\t" << a.sub_of_elems;
    }
    ~Subtructor() {}
};
class Multiplier {
private:
    int mul_of_elems = 1;
public:
    Multiplier() {}
    Multiplier(int * st) {
        vector<int> output;
        for (int i = 0; i < 6; i++) {
            output.push_back(st[i]);
        }
        for (vector<int>::iterator it = output.begin(); it != output.end(); ++it)
            mul_of_elems *= *it;
    }
    void printMul(Multiplier a) {
        cout << "MUL\t" << a.mul_of_elems;
    }
    ~Multiplier() {}
};
class Divisior {
private:
    int div_of_elems = 1;
public:
    Divisior() {}
    Divisior(int * st) {
        vector<int> output;
        for (int i = 0; i < 6; i++) {
            if (i == 0) {
                div_of_elems = st[i];
            }
            else {
                output.push_back(st[i]);
            }
        }
        for (vector<int>::iterator it = output.begin(); it != output.end(); ++it)
            div_of_elems /= *it;
    }
    void printDiv(Divisior a) {
        cout << "DIV\t" << a.div_of_elems;
    }
    ~Divisior() {}
};
int main()
{
    string line = "20+2+2+2+2";
    stringstream ss(line);
    vector<int> v;
    copy(istream_iterator<int>(ss), {}, back_inserter(v));
    copy(begin(v), end(v), ostream_iterator<int>(cout, "+"));
    int arr[5];
    copy(v.begin(), v.end(), arr);
    Sumator a (arr);
    a.printSum(a);
}
