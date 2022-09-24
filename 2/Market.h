#pragma once
#include "IShopFunc.h"
#include <string>
class Market : public IShopFunc
{
private:
    std::string m_title;//�������� �����
    int m_shopcount;//���������� �������
    int  m_arenda;//�������� �������
    bool m_hasSportInvent;
public:
    //�����������
    Market();
    //����������� � �����������
    Market(std::string _title, int  _shopcount, int _arenda, bool _hasSportInvent);
    //����������� ����������
    ~Market();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
};