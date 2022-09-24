#include "BarberShop.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
BarberShop::BarberShop() {};
BarberShop::BarberShop(string _title, int  _clcount, int _midcheck) {
    m_title = _title;
    m_clcount = _clcount;
    m_midcheck = _midcheck;
}
BarberShop::~BarberShop() {} //����������
//������
void BarberShop::setter(){
    cout << "������� ��������: " << endl;
    if (char(cin.peek()) == '\n')//������� ������� �����
        cin.ignore();

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
    }
    getline(std::cin, m_title);

    cout << "������� ������� ���-�� �������� �� ����: " << endl;
    cin >> m_clcount;

    cout << "������� ������� ���" << endl;
    cin >> m_midcheck;
}
//����� ��� ����������� ����������
void BarberShop::displayShop(){
    cout << "\n�������� ����������: " << m_title << "\n���������� �������� � ������� � ����: " << m_clcount
        << "\n������� ���: " << m_midcheck << " ���." << endl;
}
//������ ������� � ����
void BarberShop::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_clcount << "\n" << m_midcheck << "\n";
    fout.close();
}
//������ ������� �� �����
void BarberShop::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_clcount >> m_midcheck;
    fin.close();
}