#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
class IShopFunc {
public:
    virtual void setter() = 0;
    virtual void displayShop() = 0;
    virtual void seriallize(const std::string filename) = 0;
    virtual void deseriallize(const std::string filename) = 0;
};
//Класс 
class Shop : public IShopFunc
{
private:
    string title;//Название магазина
    int year;//Год основания
    long long number;//Номер телефона
    long long  networth;//Суммарная прибыль
    bool preorder;
public:
    //КОНСТРУКТОР
    Shop(string _title, int _year, long long _number, long long _networth, bool _preorder) {
        title = _title;
        year = _year;
        number = _number;
        networth = _networth;
        preorder = _preorder;
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
        getline(std::cin, title);

        cout << "Введите год: " << endl;
        cin >> year;

        cout << "Введите номер: " << endl;
        cin >> number;

        cout << "Введите заработок: " << endl;
        cin >> networth;
        int tmp;
        cout << "Возможен ли предзаказ?\n1. Да\n2. Нет" << endl;
        cin >> tmp;
        if (tmp == 1)  preorder = TRUE;
        else preorder == FALSE;
    }
    //МЕТОД ДЛЯ ОТОБРАЖЕНИЯ МАГАЗИНА
    virtual void displayShop() override {
        std::cout << title << "\n"
            << year << " года основания\n"
            << "Номер телефона: " << number << "\n"
            << "Суммарная прибыль: " << networth << " руб." << "\n"
            << "Предзаказ ";
        if (preorder) cout << "возможен" << endl;
        else cout << "невозможен" << endl;
    }
    //ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
    virtual void seriallize(const std::string filename) override {
        std::ofstream fout;
        fout.open(filename);
        fout << title << "\n" << year << "\n" << number << "\n" << networth;
        fout.close();
    }
    //ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
    virtual void deseriallize(const std::string filename) override {
        std::ifstream fin;
        fin.open(filename);
        fin >> title >> year >> number >> networth;
        fin.close();
    }
};
//Класс Рынок
class Market : public IShopFunc
{
private:
    string title;//Название рынка
    int shopcount;//Количество киосков
    int  arenda;//Месячная прибыль
    bool sportinvent;
public:
    //КОНСТРУКТОР
    Market(string _title, int  _shopcount, int _arenda,  bool _sportinvent) {
        title = _title;
        shopcount = _shopcount;
         arenda= _arenda;
        sportinvent= _sportinvent;
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
        getline(std::cin, title);

        cout << "Введите количество магазинов: " << endl;
        cin >> shopcount;

        cout << "Введите среднюю плату за аренду: " << endl;
        cin >> arenda;
        int tmp;
        cout << "Можно ли там купить спорт. инвентарь?\n1. Да\n2. Нет" << endl;
        cin >> tmp;
        if (tmp == 1)  sportinvent == TRUE;
        else sportinvent == FALSE;
    }
    //МЕТОД ДЛЯ ОТОБРАЖЕНИЯ МАГАЗИНА
    virtual void displayShop() override {
        cout << "Название рынка: " << title << "\nКоличество магазинов: " << shopcount
            << "\nСредняя плата за аренду: " << arenda << " руб.\nСпорт. инвентарь в продаже: ";
        if (sportinvent) cout << "имеется" << endl;
        else cout << "отсутствует" << endl;
    }
    //ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
    virtual void seriallize(const std::string filename) override {
        std::ofstream fout;
        fout.open(filename);
        fout << title << "\n" << shopcount << "\n" << arenda << "\n" << sportinvent;
        fout.close();
    }
    //ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
    virtual void deseriallize(const std::string filename) override {
        std::ifstream fin;
        fin.open(filename);
        fin >> title >> shopcount >>  arenda >>  sportinvent;
        fin.close();
    }
};
//Класс Рынок
class  BarberShop: public IShopFunc
{
private:
    string title;//Название рынка
    int clcount;//Количество посетителей в день
    int  midcheck;//Средний чек
public:
    //КОНСТРУКТОР
    BarberShop(string _title, int  _clcount, int _midcheck) {
        title = _title;
        clcount = _clcount;
        midcheck = _midcheck;
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
        getline(std::cin, title);

        cout << "Введите среднее кол-во клиентов за день: " << endl;
        cin >> clcount;

        cout << "Введите средний чек" << endl;
        cin >> midcheck;
    }
    //МЕТОД ДЛЯ ОТОБРАЖЕНИЯ МАГАЗИНА
    virtual void displayShop() override {
        cout << "Название Барбершопа: " << title << "\nКоличество клиентов в среднем в день: " << clcount
            << "\nСредний чек: " << midcheck<<" руб.";
    }
    //ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
    virtual void seriallize(const std::string filename) override {
        std::ofstream fout;
        fout.open(filename);
        fout << title << "\n" << clcount << "\n" << midcheck << "\n";
        fout.close();
    }
    //ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
    virtual void deseriallize(const std::string filename) override {
        std::ifstream fin;
        fin.open(filename);
        fin >> title >> clcount >> midcheck;
        fin.close();
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<Shop> shop;
    cout << "Магазинчик" << endl;
    Shop example( "Пятерочка" ,1998, 88005555505, 178000000000, TRUE);
    shop.push_back(example);
    example.displayShop();
    example.seriallize("file.txt");
    Market a("Сокол",60,2300,TRUE);
    cout << "\nНевероятный эксперт в области ООП" << endl;
    a.displayShop();
    BarberShop z("Шалость", 24, 3100);
    cout << "\nСходил в этот ваш БарбиШОп"<<endl;
    z.displayShop();
}

