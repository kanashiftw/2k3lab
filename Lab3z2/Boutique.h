#pragma once
#include "IPayTax.h"
#include "IShopFunc.h"
#include <string>
class  Boutique : public IShopFunc, public IPayTax
{
private:
    std::string m_title;//�������� �����
    int m_year;
    int m_workinHours;//���������� ����������� � ����
    int  m_income;//������� ���
public:
    //�����������
    Boutique();
    //����������� � �����������
    Boutique(std::string _title, int _year, int  _workinHours, int _income);
    //����������� ����������
    ~Boutique();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
    virtual void payTax() override;
};