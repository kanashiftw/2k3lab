#pragma once
#include "IPayTax.h"
#include "IShopFunc.h"
#include <string>
class  Boutique : public IShopFunc, public IPayTax
{
private:
    std::string m_title;//Название рынка
    int m_year;
    int m_workinHours;//Количество посетителей в день
    int  m_income;//Средний чек
public:
    //КОНСТРУКТОР
    Boutique();
    //КОНСТРУКТОР С ПАРАМЕТРАМИ
    Boutique(std::string _title, int _year, int  _workinHours, int _income);
    //ВИРТУАЛЬНЫЙ ДЕСТРУКТОР
    ~Boutique();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
    virtual void payTax() override;
};