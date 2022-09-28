#pragma once
#include "IPayTax.h"
#include "IShopFunc.h"
class Pharmacy : public IShopFunc, public IPayTax
{
private:
    std::string m_title;
    int m_year;
    int m_discountUsers;
    int m_dayIncome;
    bool m_aroundTheClock;
public:
    //�����������
    Pharmacy();
    //����������� � �����������
    Pharmacy(std::string _title, int  _year, int _discountUsers, int _dayIncome, bool _aroundTheClock);
    //����������� ����������
    ~Pharmacy();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
    virtual void payTax()override;
};