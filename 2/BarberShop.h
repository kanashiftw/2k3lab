#pragma once
#include "IShopFunc.h"
#include <string>
class  BarberShop : public IShopFunc
{
private:
    std::string m_title;//�������� �����
    int m_clcount;//���������� ����������� � ����
    int  m_midcheck;//������� ���
public:
    //�����������
    BarberShop();
    //����������� � �����������
    BarberShop(std::string _title, int  _clcount, int _midcheck);
    //����������� ����������
    ~BarberShop();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
};