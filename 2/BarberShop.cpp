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
BarberShop::~BarberShop() {} //Деструктор
//СЕТТЕР
void BarberShop::setter(){
    cout << "Введите название: " << endl;
    if (char(cin.peek()) == '\n')//Очистка буффера ввода
        cin.ignore();

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
    }
    getline(std::cin, m_title);

    cout << "Введите среднее кол-во клиентов за день: " << endl;
    cin >> m_clcount;

    cout << "Введите средний чек" << endl;
    cin >> m_midcheck;
}
//МЕТОД ДЛЯ ОТОБРАЖЕНИЯ БАРБЕРШОПА
void BarberShop::displayShop(){
    cout << "\nНазвание Барбершопа: " << m_title << "\nКоличество клиентов в среднем в день: " << m_clcount
        << "\nСредний чек: " << m_midcheck << " руб." << endl;
}
//ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
void BarberShop::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_clcount << "\n" << m_midcheck << "\n";
    fout.close();
}
//ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
void BarberShop::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_clcount >> m_midcheck;
    fin.close();
}