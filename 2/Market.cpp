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
Market::~Market() {} //Деструктор
//СЕТТЕР
void Market::setter(){
    cout << "Введите название: " << endl;
    if (char(cin.peek()) == '\n')//Очистка буффера ввода
        cin.ignore();

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
    }
    getline(std::cin, m_title);

    cout << "Введите количество магазинов: " << endl;
    cin >> m_shopcount;

    cout << "Введите среднюю плату за аренду: " << endl;
    cin >> m_arenda;
    int tmp;
    cout << "Можно ли там купить спорт. инвентарь?\n1. Да\n2. Нет" << endl;
    cin >> tmp;
    if (tmp == 1)  m_hasSportInvent = TRUE;
    else m_hasSportInvent = FALSE;
}
//МЕТОД ДЛЯ ОТОБРАЖЕНИЯ РЫНКА
void Market::displayShop(){
    cout << "\nНазвание рынка: " << m_title << "\nКоличество магазинов: " << m_shopcount
        << "\nСредняя плата за аренду: " << m_arenda << " руб.\nСпорт. инвентарь в продаже: ";
    if (m_hasSportInvent) cout << "имеется" << endl;
    else cout << "отсутствует" << endl;
}
//ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
void Market::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_shopcount << "\n" << m_arenda << "\n" << m_hasSportInvent;
    fout.close();
}
//ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
void Market::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_shopcount >> m_arenda >> m_hasSportInvent;
    fin.close();
}