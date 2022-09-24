#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "IShopFunc.h"
#include "Shop.h"
#include "Pharmacy.h"
#include "Boutique.h"
using namespace std;//Бяка


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Shop shop_test("Пятерочка", 1998, 88005555505, 178000000000, TRUE);
    shop_test.displayShop();
    shop_test.seriallize("file.txt");
    Pharmacy pharmacy_test("Ромашка", 1997, 2300, 13900, TRUE);;
    pharmacy_test.displayShop();
    pharmacy_test.seriallize("file.txt");
    Boutique boutique_test("Олег",1920, 12, 310020);
    boutique_test.displayShop();
    //RTTI
    Boutique* a = new Boutique;
    IShopFunc* b = dynamic_cast<IShopFunc*>(a);
    cout << "\n\nРезультат приведения dynamic_cast для Boutique:" << endl;
    if (b) cout << "\tПриведение корректно.\nБазовый класс: " << typeid(b).name() << "\nПолученный класс: " << typeid(a).name();
    else cout << "\tПриведение некорректно." << endl;
}

