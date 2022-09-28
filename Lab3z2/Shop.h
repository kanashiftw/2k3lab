#pragma once
#include "IPayTax.h"
#include "IShopFunc.h"
#include "Address.h"
class Shop : public IShopFunc, public IPayTax
{
private:
    std::string m_title;
    int m_year;
    Address m_adr;
    long long m_number;
    long long  m_networth;
    bool m_preorder;
public:
    //�����������
    Shop();
    //����������� � �����������
    Shop(std::string _title, int _year, Address _adr, long long _number, long long _networth, bool _preorder);
    //����������� ����������
    ~Shop();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
    virtual void payTax() override;
};