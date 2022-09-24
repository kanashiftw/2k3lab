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
Pharmacy::~Pharmacy() {} //Деструктор
//СЕТТЕР
void Pharmacy::setter(){
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

    cout << "Введите количество обладателей дисконта: " << endl;
    cin >> m_discountUsers;
    cout << "Введите дневной доход"<<endl;
    cin >> m_dayIncome;
    int tmp;
    cout << "Можно ли там купить спорт. инвентарь?\n1. Да\n2. Нет" << endl;
    cin >> tmp;
    if (tmp == 1)  m_aroundTheClock = TRUE;
    else m_aroundTheClock = FALSE;
}
//МЕТОД ДЛЯ ОТОБРАЖЕНИЯ АПТЕКИ
void Pharmacy::displayShop(){
    payTax();
    cout << "\nНазвание аптеки: " << m_title << "\n" << m_year << " года основания."
        << "\nКоличество обладателей дисконта: " << m_discountUsers << "\nДневной доход: "<<m_dayIncome<< endl;
    if (m_aroundTheClock) cout << "Круглосуточно." << endl;
    else cout << "Не круглосуточно." << endl;
}
//ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
void Pharmacy::seriallize(const std::string filename){
    std::ofstream fout;
    fout.open(filename);
    fout << m_title << "\n" << m_year << "\n" << m_discountUsers<< "\n" << m_aroundTheClock;
    fout.close();
}
//ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
void Pharmacy::deseriallize(const std::string filename){
    std::ifstream fin;
    fin.open(filename);
    fin >> m_title >> m_year >> m_discountUsers >> m_aroundTheClock;
    fin.close();
}
void Pharmacy::payTax() {
    double Tax = m_dayIncome * (NDFL + NDS + LAND);
    m_dayIncome -= Tax;
    cout << "\nВычтенный налог: " << Tax << " руб.";
}