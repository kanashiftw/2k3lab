#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
string cleaned(string s1)
{
    string cl;
    for (int i = 0;i < s1.length();i++)
    {
        if (s1[i] - '0' >= 0 && s1[i] - '0' <= 9)
        {
            cl += s1[i];
        }
    }
    return cl;
}

class Sumator {
private:
    int sum_of_elems = 0;
public:
    Sumator() {}
    Sumator(string text) {
        string st =  cleaned(text);
        vector<int> output;
        for (int i = 0; i < st.length(); i++) {
            char c = st[i];
            int temp = atoi(&c);
            output.push_back(temp);
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
    Subtructor(string text) {
        string st = cleaned(text);
        vector<int> output;
        for (int i = 0; i < st.length(); i++) {
            char c = st[i];
            if (i == 0) {
                int temp = atoi(&c);
                sub_of_elems = temp;
            }
            else {
                int temp = atoi(&c);
                output.push_back(temp);
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
    Multiplier(string text) {
        string st = cleaned(text);
        vector<int> output;
        for (int i = 0; i < st.length(); i++) {
            char c = st[i];
            int temp = atoi(&c);
            output.push_back(temp);
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
    Divisior(string text) {
        string st = cleaned(text);
        vector<int> output;
        for (int i = 0; i < st.length(); i++) {
            char c = st[i];
            if (i == 0) {
                int temp = atoi(&c);
                div_of_elems = temp;
            }
            else {
                int temp = atoi(&c);
                output.push_back(temp);
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
    string line = "8/2/2";
    Divisior a (line);
    a.printDiv(a);
}


