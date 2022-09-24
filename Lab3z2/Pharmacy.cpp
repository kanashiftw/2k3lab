#include "Pharmacy.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
Pharmacy::Pharmacy() {};
Pharmacy::Pharmacy(string _title, int  _year, int _discountUsers, int _dayIncome, bool _aroundTheClock) {
    m_title = _title;
    m_year = _year;
    m_discountUsers = _discountUsers;
    m_dayIncome = _dayIncome;
    m_aroundTheClock = _aroundTheClock;
}
Pharmacy::~Pharmacy() {} //����������
//������
void Pharmacy::setter(){
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

    cout << "������� ���������� ����������� ��������: " << endl;
    cin >> m_discountUsers;
    cout << "������� ������� �����"<<endl;
    cin >> m_dayIncome;
    int tmp;
    cout << "����� �� ��� ������ �����. ���������?\n1. ��\n2. ���" << endl;
    cin >> tmp;
    if (tmp == 1)  m_aroundTheClock = TRUE;
    else m_aroundTheClock = FALSE;
}
//����� ��� ����������� ������
void Pharmacy::displayShop(){
    payTax();
    cout << "\n�������� ������: " << m_title << "\n" << m_year << " ���� ���������."
        << "\n���������� ����������� ��������: " << m_discountUsers << "\n������� �����: "<<m_dayIncome<< endl;
    if (m_aroundTheClock) cout << "�������������." << endl;
    else cout << "�� �������������." << endl;
}
//������ ������� � ����
void Pharmacy::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_year << "\n" << m_discountUsers<< "\n" << m_aroundTheClock;
    fout.close();
}
//������ ������� �� �����
void Pharmacy::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_year >> m_discountUsers >> m_aroundTheClock;
    fin.close();
}
void Pharmacy::payTax() {
    double Tax = m_dayIncome * (NDFL + NDS + LAND);
    m_dayIncome -= Tax;
    cout << "\n��������� �����: " << Tax << " ���.";
}