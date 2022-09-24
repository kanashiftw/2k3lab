#pragma once
#include "IShopFunc.h"
#include <string>
class Market : public IShopFunc
{
private:
    std::string m_title;//Название рынка
    int m_shopcount;//Количество киосков
    int  m_arenda;//Месячная прибыль
    bool m_hasSportInvent;
public:
    //КОНСТРУКТОР
    Market();
    //КОНСТРУКТОР С ПАРАМЕТРАМИ
    Market(std::string _title, int  _shopcount, int _arenda, bool _hasSportInvent);
    //ВИРТУАЛЬНЫЙ ДЕСТРУКТОР
    ~Market();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
};