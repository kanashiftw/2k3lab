#include "Boutique.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
Boutique::Boutique() {};
Boutique::Boutique(string _title,int _year, int  _workinHours, int _income) {
    m_title = _title;
    m_year = _year;
    m_workinHours = _workinHours;
    m_income = _income;
}
Boutique::~Boutique() {} //����������
//������
void Boutique::setter(){
    cout << "������� ��������: " << endl;
    if (char(cin.peek()) == '\n')//������� ������� �����
        cin.ignore();

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
    }
    getline(std::cin, m_title);

    cout << "������� ��� ���������: " << endl;
    cin >> m_year;

    cout << "������� ���� ������" << endl;
    cin >> m_workinHours;
    
    cout << "������� ��������� �� �����: " << endl;
    cin >> m_income;
}
//����� ��� ����������� ������

void Boutique::displayShop(){
    payTax();
    cout << "\n�������� ������: " << m_title <<'\n'<< m_year<<" ���� ���������."
        << "\n���� ������: " << m_workinHours << " ����� � ����\n"<<"�����: "<<m_income <<" ���."<<endl;
}
//������ ������� � ����
void Boutique::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_year << "\n" << m_workinHours << "\n"<<m_income;
    fout.close();
}
//������ ������� �� �����
void Boutique::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_year >> m_workinHours>>m_income;
    fin.close();
}
void Boutique::payTax() {
    double Tax = m_income * (NDFL + NDS);
    m_income -= Tax;
    cout << "\n��������� �����: " << Tax << " ���.";
}