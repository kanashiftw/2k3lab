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
Boutique::~Boutique() {} //Деструктор
//СЕТТЕР
void Boutique::setter(){
    cout << "Введите название: " << endl;
    if (char(cin.peek()) == '\n')//Очистка буффера ввода
        cin.ignore();

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
    }
    getline(std::cin, m_title);

    cout << "Введите год основания: " << endl;
    cin >> m_year;

    cout << "Введите часы работы" << endl;
    cin >> m_workinHours;
    
    cout << "Введите заработок за месяц: " << endl;
    cin >> m_income;
}
//МЕТОД ДЛЯ ОТОБРАЖЕНИЯ БУТИКА

void Boutique::displayShop(){
    payTax();
    cout << "\nНазвание Бутика: " << m_title <<'\n'<< m_year<<" года основания."
        << "\nЧасы работы: " << m_workinHours << " часов в день\n"<<"Доход: "<<m_income <<" руб."<<endl;
}
//ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
void Boutique::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_year << "\n" << m_workinHours << "\n"<<m_income;
    fout.close();
}
//ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
void Boutique::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_year >> m_workinHours>>m_income;
    fin.close();
}
void Boutique::payTax() {
    double Tax = m_income * (NDFL + NDS);
    m_income -= Tax;
    cout << "\nВычтенный налог: " << Tax << " руб.";
}