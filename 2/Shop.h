#pragma once
#include "IShopFunc.h"
#include <string>
class Shop : public IShopFunc
{
private:
    std::string m_title;//Название магазина
    int m_year;//Год основания
    long long m_number;//Номер телефона
    long long  m_networth;//Суммарная прибыль
    bool m_preorder;
public:
    //КОНСТРУКТОР
    Shop();
    //КОНСТРУКТОР С ПАРАМЕТРАМИ
    Shop(std::string _title, int _year, long long _number, long long _networth, bool _preorder);
    //ВИРТУАЛЬНЫЙ ДЕСТРУКТОР
    ~Shop();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
};