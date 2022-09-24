#pragma once
#include "IShopFunc.h"
#include <string>
class  BarberShop : public IShopFunc
{
private:
    std::string m_title;//Название рынка
    int m_clcount;//Количество посетителей в день
    int  m_midcheck;//Средний чек
public:
    //КОНСТРУКТОР
    BarberShop();
    //КОНСТРУКТОР С ПАРАМЕТРАМИ
    BarberShop(std::string _title, int  _clcount, int _midcheck);
    //ВИРТУАЛЬНЫЙ ДЕСТРУКТОР
    ~BarberShop();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
};