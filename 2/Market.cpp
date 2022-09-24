#include "Market.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
Market::Market() {};
Market::Market(string _title, int  _shopcount, int _arenda, bool _hasSportInvent) {
    m_title = _title;
    m_shopcount = _shopcount;
    m_arenda = _arenda;
    m_hasSportInvent = _hasSportInvent;
}
Market::~Market() {} //����������
//������
void Market::setter(){
    cout << "������� ��������: " << endl;
    if (char(cin.peek()) == '\n')//������� ������� �����
        cin.ignore();

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
    }
    getline(std::cin, m_title);

    cout << "������� ���������� ���������: " << endl;
    cin >> m_shopcount;

    cout << "������� ������� ����� �� ������: " << endl;
    cin >> m_arenda;
    int tmp;
    cout << "����� �� ��� ������ �����. ���������?\n1. ��\n2. ���" << endl;
    cin >> tmp;
    if (tmp == 1)  m_hasSportInvent = TRUE;
    else m_hasSportInvent = FALSE;
}
//����� ��� ����������� �����
void Market::displayShop(){
    cout << "\n�������� �����: " << m_title << "\n���������� ���������: " << m_shopcount
        << "\n������� ����� �� ������: " << m_arenda << " ���.\n�����. ��������� � �������: ";
    if (m_hasSportInvent) cout << "�������" << endl;
    else cout << "�����������" << endl;
}
//������ ������� � ����
void Market::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_shopcount << "\n" << m_arenda << "\n" << m_hasSportInvent;
    fout.close();
}
//������ ������� �� �����
void Market::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_shopcount >> m_arenda >> m_hasSportInvent;
    fin.close();
}