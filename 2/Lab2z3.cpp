#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "IShopFunc.h"
#include "Shop.h"
#include "Market.h"
#include "BarberShop.h"
using namespace std;//Бяка


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
    if (b) cout << "\tПриведение корректно.\nБазовый класс: " << typeid(b).name() << "\nПолученный класс: " << typeid(a).name();
    else cout << "\tПриведение некорректно." << endl;
}

