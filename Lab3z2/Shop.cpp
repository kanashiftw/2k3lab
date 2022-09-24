#include "Shop.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
Shop::Shop() {}
Shop::Shop(string _title, int _year, long long _number, long long _networth, bool _preorder) {
    m_title = _title;
    m_year = _year;
    m_number = _number;
    m_networth = _networth;
    m_preorder = _preorder;
}
Shop::~Shop() {}
void Shop::setter(){
    std::cout << "������� ��������: " << std::endl;
    if (char(cin.peek()) == '\n')//������� ������� �����
        std::cin.ignore();

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
    getline(cin, m_title);

    cout << "������� ���: " << std::endl;
    cin >> m_year;

    cout << "������� �����: " << std::endl;
    cin >> m_number;

    cout << "������� ���������: " << endl;
    cin >> m_networth;
    int tmp;
    cout << "�������� �� ���������?\n1. ��\n2. ���" << endl;
    cin >> tmp;
    if (tmp == 1)  m_preorder = TRUE;
    else m_preorder = FALSE;
}
//����� ��� ����������� ��������
void Shop::displayShop(){
    payTax();
    std::cout << "\n�������� ��������: " << m_title << "\n"
        << m_year << " ���� ���������.\n"
        << "����� ��������: " << m_number << "\n"
        << "��������� �������: " << m_networth << " ���." << "\n"
        << "��������� ";
    if (m_preorder) cout << "��������" << endl;
    else cout << "����������" << endl;
}
//������ ������� � ����
void Shop::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_year << "\n" << m_number << "\n" << m_networth;
    fout.close();
}
//������ ������� �� �����
void Shop::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_year >> m_number >> m_networth;
    fin.close();
}
void Shop::payTax() {
    long long Tax = m_networth * (NDFL + NDS);
    m_networth -= Tax;
    cout << "\n��������� �����: " << Tax << " ���.";
}
