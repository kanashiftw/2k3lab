#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <typeinfo>
using namespace std;//Бяка

//ИНТЕРФЕЙС МАГАЗИНА

class IShopFunc {
public:
    virtual void setter() = 0;
    virtual void displayShop() = 0;
    virtual void seriallize(const std::string filename) = 0;
    virtual void deseriallize(const std::string filename) = 0;
};
//КЛАСС МАГАЗИН
class Shop : public IShopFunc
{
private:
    string m_title;//Название магазина
    int m_year;//Год основания
    long long m_number;//Номер телефона
    long long  m_networth;//Суммарная прибыль
    bool m_preorder;
public:
    //КОНСТРУКТОР
	Shop(){};
    Shop(string _title, int _year, long long _number, long long _networth, bool _preorder) {
        m_title = _title;
        m_year = _year;
        m_number = _number;
        m_networth = _networth;
        m_preorder = _preorder;
    }
    ~Shop() {} //Деструктор
    //СЕТТЕР
    virtual void setter() override {
        cout << "Введите название: " << endl;
        if (char(cin.peek()) == '\n')//Очистка буффера ввода
            cin.ignore();

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        getline(cin, m_title);

        cout << "Введите год: " << endl;
        cin >> m_year;

        cout << "Введите номер: " << endl;
        cin >> m_number;

        cout << "Введите заработок: " << endl;
        cin >> m_networth;
        int tmp;
        cout << "Возможен ли предзаказ?\n1. Да\n2. Нет" << endl;
        cin >> tmp;
        if (tmp == 1)  m_preorder = TRUE;
        else m_preorder == FALSE;
    }
    //МЕТОД ДЛЯ ОТОБРАЖЕНИЯ МАГАЗИНА
    virtual void displayShop() override {
        std::cout <<'\n'<< m_title << "\n"
            << m_year << " года основания\n"
            << "Номер телефона: " << m_number << "\n"
            << "Суммарная прибыль: " << m_networth << " руб." << "\n"
            << "Предзаказ ";
        if (m_preorder) cout << "возможен" << endl;
        else cout << "невозможен" << endl;
    }
    //ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
    virtual void seriallize(const std::string filename) override {
        std::ofstream fout;
        fout.open(filename);
        fout << m_title << "\n" << m_year << "\n" << m_number << "\n" << m_networth;
        fout.close();
    }
    //ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
    virtual void deseriallize(const std::string filename) override {
        std::ifstream fin;
        fin.open(filename);
        fin >> m_title >> m_year >> m_number >> m_networth;
        fin.close();
    }
};
//КЛАСС РЫНОК
class Market : public IShopFunc
{
private:
    string m_title;//Название рынка
    int m_shopcount;//Количество киосков
    int  m_arenda;//Месячная прибыль
    bool m_hasSportInvent;
public:
    //КОНСТРУКТОР
	Market(){};
    Market(string _title, int  _shopcount, int _arenda,  bool _hasSportInvent) {
        m_title = _title;
        m_shopcount = _shopcount;
         m_arenda= _arenda;
        m_hasSportInvent= _hasSportInvent;
    }
    ~Market() {} //Деструктор
    //СЕТТЕР
    virtual void setter() override {
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
        if (tmp == 1)  m_hasSportInvent == TRUE;
        else m_hasSportInvent == FALSE;
    }
    //МЕТОД ДЛЯ ОТОБРАЖЕНИЯ РЫНКА
    virtual void displayShop() override {
        cout << "\nНазвание рынка: " << m_title << "\nКоличество магазинов: " << m_shopcount
            << "\nСредняя плата за аренду: " << m_arenda << " руб.\nСпорт. инвентарь в продаже: ";
        if (m_hasSportInvent) cout << "имеется" << endl;
        else cout << "отсутствует" << endl;
    }
    //ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
    virtual void seriallize(const std::string filename) override {
        std::ofstream fout;
        fout.open(filename);
        fout << m_title << "\n" << m_shopcount << "\n" << m_arenda << "\n" << m_hasSportInvent;
        fout.close();
    }
    //ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
    virtual void deseriallize(const std::string filename) override {
        std::ifstream fin;
        fin.open(filename);
        fin >> m_title >> m_shopcount >> m_arenda >>  m_hasSportInvent;
        fin.close();
    }
};
//КЛАСС БАРБЕРШОП
class  BarberShop: public IShopFunc
{
private:
    string m_title;//Название рынка
    int m_clcount;//Количество посетителей в день
    int  m_midcheck;//Средний чек
public:
    //КОНСТРУКТОР
	BarberShop(){};
    BarberShop(string _title, int  _clcount, int _midcheck) {
        m_title = _title;
        m_clcount = _clcount;
        m_midcheck = _midcheck;
    }
    ~BarberShop() {} //Деструктор
    //СЕТТЕР
    virtual void setter() override {
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
    virtual void displayShop() override {
        cout << "\nНазвание Барбершопа: " << m_title << "\nКоличество клиентов в среднем в день: " << m_clcount
            << "\nСредний чек: " << m_midcheck<<" руб."<<endl;
    }
    //ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
    virtual void seriallize(const std::string filename) override {
        std::ofstream fout;
        fout.open(filename);
        fout << m_title << "\n" << m_clcount << "\n" << m_midcheck << "\n";
        fout.close();
    }
    //ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
    virtual void deseriallize(const std::string filename) override {
        std::ifstream fin;
        fin.open(filename);
        fin >> m_title >> m_clcount >> m_midcheck;
        fin.close();
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Shop shop_test("Пятерочка", 1998, 88005555505, 178000000000, TRUE);
    shop_test.displayShop();
    shop_test.seriallize("file.txt");
    Market market_test("Сокол", 60, 2300, TRUE);;
    market_test.displayShop();
    market_test.seriallize("file.txt");
    BarberShop barbershop_test("Шалость", 24, 3100);
    barbershop_test.displayShop();
    //RTTI
    BarberShop* a = new BarberShop;
    IShopFunc* b = dynamic_cast<IShopFunc*>(a);
    cout << "\n\nРезультат приведения dynamic_cast для BarberShop:" << endl;
    if (b) cout << "\tПриведение корректно.\nБазовый класс: "<< typeid(b).name()<<"\nПолученный класс: "<< typeid(a).name();
    else cout << "\tПриведение некорректно." << endl;
}

