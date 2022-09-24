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
    std::cout << "Введите название: " << std::endl;
    if (char(cin.peek()) == '\n')//Очистка буффера ввода
        std::cin.ignore();

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
    getline(cin, m_title);

    cout << "Введите год: " << std::endl;
    cin >> m_year;

    cout << "Введите номер: " << std::endl;
    cin >> m_number;

    cout << "Введите заработок: " << endl;
    cin >> m_networth;
    int tmp;
    cout << "Возможен ли предзаказ?\n1. Да\n2. Нет" << endl;
    cin >> tmp;
    if (tmp == 1)  m_preorder = TRUE;
    else m_preorder = FALSE;
}
//МЕТОД ДЛЯ ОТОБРАЖЕНИЯ МАГАЗИНА
void Shop::displayShop(){
    payTax();
    std::cout << "\nНазвание магазина: " << m_title << "\n"
        << m_year << " года основания.\n"
        << "Номер телефона: " << m_number << "\n"
        << "Суммарная прибыль: " << m_networth << " руб." << "\n"
        << "Предзаказ ";
    if (m_preorder) cout << "возможен" << endl;
    else cout << "невозможен" << endl;
}
//ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
void Shop::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_year << "\n" << m_number << "\n" << m_networth;
    fout.close();
}
//ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
void Shop::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_year >> m_number >> m_networth;
    fin.close();
}
void Shop::payTax() {
    long long Tax = m_networth * (NDFL + NDS);
    m_networth -= Tax;
    cout << "\nВычтенный налог: " << Tax << " руб.";
}
